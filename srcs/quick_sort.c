/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:24:33 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/15 16:46:45 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
// #include "libft.h"

void	normalize(t_stack *s)
{
	int	*normalized;
	int	i;
	int	j;
	int	count;

	if (s->size <= 1)
		return ;
	normalized = ft_calloc(sizeof(int), s->size);
	if (!normalized)
		return ;
	i = 0;
	while (i < (int)s->size)
	{
		count = 0;
		j = 0;
		while (j < (int)s->size)
		{
			if (s->stack[j] < s->stack[i])
				count++;
			j++;
		}
		normalized[i] = count;
		i++;
	}
	free(s->stack);
	s->stack = normalized;
}

static int	get_max_bits(size_t size)
{
	unsigned int	max_bits;
	unsigned int	max_nb;

	max_nb = size - 1;
	max_bits = 0;
	while (max_nb >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort_remi(t_stack *a, t_stack *b)
{
	size_t	i;
	int		bit;
	size_t	size;
	int		max_bits;

	normalize(a);
	bit = 0;
	max_bits = get_max_bits(a->size - 1);
	while (bit < max_bits)
	{
		if (check_sort(*a))
			return ;
		i = 0;
		size = a->size;
		while (i < size)
		{
			if (((a->stack[0] >> bit) & 1) == 1)
				universal_rotate(*a, 0);
			else
				push(a, b);
			i++;
		}
		bit++;
		size = b->size;
		i = 0;
		while (i < size)
		{
			if (((b->stack[0] >> bit) & 1) == 0)
				universal_rotate(*b, 0);
			else
				push(b, a);
			i++;
		}
	}
	while (b->size)
		push(b, a);
}

