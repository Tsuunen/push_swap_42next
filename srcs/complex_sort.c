/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:40:40 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/16 11:34:56 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

static int	has_bitdiff(t_stack *s, int *bit)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if ((s->stack[i] & (1 << (*bit))) != (s->stack[i - 1] & (1 << (*bit))))
			return (1);
		i++;
	}
	(*bit)++;
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
			if (s->stack[j++] < s->stack[min])
				min = j - 1;
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
		push(src, dest);
	else if (!(src->stack[0] & (1 << bit)) && !state)
		push(src, dest);
	else
		universal_rotate(*src, 0);
}

void	move_stack(t_stack *src, t_stack *dest, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = src->size;
	while (i < size)
	{
		if (src->name == 'a' && check_strict_sort(src))
			break ;
		push_skip(src, dest, bit, src->name == 'b');
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;

	bit = 0;
	if (normalize(a))
		return ;
	for (size_t i = 0; i < a->size; i--)
		ft_printf("%d \n", a->stack[i]);
	while (!check_strict_sort(a) && bit <= 32)
	{
		if (!has_bitdiff(a, &bit))
			continue ;
		move_stack(a, b, bit);
		if (!check_strict_sort_reverse(b))
			move_stack(b, a, bit + 1);
		bit++;
	}
	while (b->size)
		push(b, a);
}
