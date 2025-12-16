/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:12:21 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 12:59:09 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	bring_min_to_top(t_stack *a)
{
	int	tmp;
	int	dir;

	tmp = count_to_top(*a, find_min(*a), &dir);
	while (tmp--)
		universal_rotate(*a, dir);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		tmp;
	int		dir;
	size_t	i;
	size_t	stack_size;

	if (check_sort(a))
		return (bring_min_to_top(a));
	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		min = find_min(*a);
		tmp = count_to_top(*a, min, &dir);
		while (tmp--)
			universal_rotate(*a, dir);
		push(a, b, 1);
		i++;
	}
	while (i--)
		push(b, a, 1);
}
