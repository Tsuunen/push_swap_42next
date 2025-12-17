/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:40:40 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/17 11:36:40 by relaforg         ###   ########.fr       */
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
		if ((s->stack[i] & (1 << (bit))) != (s->stack[i - 1] & (1 << (bit))))
			return (1);
		i++;
	}
	return (0);
}

int	normalize(t_stack *s)
{
	int	*normalized;
	int	i;
	int	j;
	int	count;

	if (s->size <= 1)
		return (1);
	normalized = ft_calloc(sizeof(int), s->size);
	if (!normalized)
		return (1);
	i = -1;
	while (++i < (int)s->size)
	{
		count = 0;
		j = -1;
		while (++j < (int)s->size)
			if (s->stack[j] < s->stack[i])
				count++;
		normalized[i] = count;
	}
	free(s->stack);
	s->stack = normalized;
	return (0);
}

static void	push_skip_0(t_stack *src, t_stack *dest, int bit, int *op_nbr)
{
	if (!(src->stack[0] & (1 << bit)))
		push(src, dest, 1, op_nbr);
	else
		universal_rotate(*src, 0, op_nbr);
}

static void	push_skip_1(t_stack *src, t_stack *dest, int bit, int *op_nbr)
{
	if ((src->stack[0] & (1 << bit)))
		push(src, dest, 1, op_nbr);
	else
		universal_rotate(*src, 0, op_nbr);
}

void	move_stack(t_stack *src, t_stack *dest, int bit, int *op_nbr)
{
	int	i;
	int	size;

	i = 0;
	size = src->size;
	while (i < size)
	{
		if (src->name == 'a' && check_strict_sort(src)
			&& !has_bitdiff(src, bit + 1)
			&& !has_bitdiff(dest, bit + 1))
			break ;
		if (src->name == 'a')
			push_skip_0(src, dest, bit, op_nbr);
		else
			push_skip_1(src, dest, bit, op_nbr);
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b, int *op_nbr)
{
	int	bit;

	bit = 0;
	if (normalize(a))
		return ;
	while (!check_strict_sort(a) && bit <= 32)
	{
		if (!has_bitdiff(a, bit))
		{
			bit++;
			continue ;
		}
		move_stack(a, b, bit, op_nbr);
		if (!check_strict_sort_reverse(b))
			move_stack(b, a, bit + 1, op_nbr);
		bit++;
	}
	while (b->size)
		push(b, a, 1, op_nbr);
}
