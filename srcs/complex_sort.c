/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:40:40 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/10 12:55:51 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	has_bitdiff(t_stack *s, int bit)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if ((s->stack[i] & (1 << bit)) != (s->stack[i - 1] & (1 << bit)))
			return (1);
		i++;
	}
	return (0);
}

static void push_skip(t_stack *src, t_stack *dest, int bit)
{
	if (!(src->stack[0] & (1 << bit)))
		push(src, dest);
	else
		universal_rotate(*src, 0);
}

void	radix_sort(t_stack *a, t_stack  *b)
{
	int	bit;
	int	bottom;

	bit = 0;
	while (!check_sort(*a) && bit < 16)
	{
		if (!has_bitdiff(a, bit))
		{
			bit++;
			continue;
		}
		bottom = a->stack[a->size - 1];
		while (a->stack[0] != bottom)
			push_skip(a, b, bit);
		push_skip(a, b, bit);
		while (b->size)
			push(b, a);
		bit++;
	}
}
