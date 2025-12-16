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

/*static int	normalize(t_stack *s)
{
	int		*new;
	char	*used;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s || s->size == 0)
		return (0);
	new = ft_calloc(s->size, sizeof(int));
	used = ft_calloc(s->size, sizeof(char));
	if (!new || !used)
	{
		free(new);
		free(used);
		return (1);
	}
	count = 0;
	while (count < s->size)
	{
		j = (size_t) - 1;
		for (i = 0; i < s->size; i++)
		{
			if (used[i])
				continue;
			if (j == (size_t) - 1 || s->stack[i] < s->stack[j])
				j = i;
		}
		used[j] = 1;
		new[j] = count;
		count++;
	}
	free(used);
	free(s->stack);
	s->stack = new;
	return (0);
}*/

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
			if (s->stack[j] < min)
				min = j;
			j++;
		}
		new[j] = i;
		s->stack[j] = INT_MAX;
		i++;
	}
	free(s->stack);
	s->stack = new;
	return (0);
}

static void push_skip(t_stack *src, t_stack *dest, int bit, int state)
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
	for (size_t i = 0; i < a->size; i++)
		ft_printf("%d, ", a->stack[i]);
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
		if (!check_sort_reverse(*b))
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
