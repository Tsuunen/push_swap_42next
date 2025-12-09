/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:12:21 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/09 12:30:39 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		tmp;
	int		dir;
	size_t	i;
	size_t	stack_size;

	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		min = find_min(*a);
		tmp = count_to_top(*a, min, &dir);
		while (tmp--)
			universal_rotate(*a, dir);
		push(a, b);
		i++;
	}
	while (i--)
		push(b, a);
}
