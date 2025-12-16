/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:40:40 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/16 10:54:13 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

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

static int	normalize(t_stack *s)
{
	int		*new;
	size_t	i;
	size_t	j;
	int		min;

	new = ft_calloc(s->size, sizeof(int));
	if (!new)
		return (1);
	i = 0;
	while (i < s->size)
	{
		j = 0;
		min = 0;
		while (j < s->size)
		{
			if (s->stack[j] < s->stack[min])
				min = j;
			j++;
		}
		new[min] = i;
		s->stack[min] = INT_MAX;
		i++;
	}
	free(s->stack);
	s->stack = new;
	return (0);
}

static void	push_skip(t_stack *src, t_stack *dest, int bit, int state)
{
	if ((src->stack[0] & (1 << bit)) && state)
		push(src, dest, 1);
	else if (!(src->stack[0] & (1 << bit)) && !state)
		push(src, dest, 1);
	else
		universal_rotate(*src, 0);
}

void	radix_sort(t_stack *a, t_stack  *b)
{
	int	bit;
	int	i;
	int	size;

	bit = 0;
	if (normalize(a))
		return ;
	while (!check_strict_sort(a) && bit <= 32)
	{
		if (!has_bitdiff(a, bit))
		{
			bit++;
			continue;
		}
		i = 0;
		size = a->size;
		while (++i <= size)
			push_skip(a, b, bit, 0);
		if (!check_strict_sort_reverse(b))
		{
			i = 0;
			size = b->size;
			while (++i <= size)
				push_skip(b, a, bit + 1, 1);
		}
		bit++;
	}
	while (b->size)
		push(b, a, 1);
}
/*void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	i;
	int	size;

	bit = 0;
	if (normalize(a))
		return ;
	while (!check_sort(*a) && bit <= 32)
	{
		if (!has_bitdiff(a, bit))
		{
			bit++;
			continue;
		}
		i = 0;
		size = a->size;
		while (++i <= size)
			push_skip(a, b, bit, 0);
		bit++;
		while (b->size)
			push(b, a);
	}
}*/
