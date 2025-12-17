/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:34:09 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 13:16:35 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	handle_max(t_stack s, int *direction)
{
	int	max;
	int	tmp;

	max = find_max(s);
	if (max == 0)
	{
		*direction = 0;
		return (1);
	}
	if (count_to_top(s, max, direction)
		< count_to_top(s, find_max(s), direction))
		tmp = count_to_top(s, max, direction);
	else
		tmp = count_to_top(s, find_max(s), direction);
	if (*direction == 0)
		return (tmp + 1);
	return (tmp - 1);
}

int	manage_minmax_reverse(t_stack s, int value, int *direction)
{
	int	min;
	int	max;

	max = find_max(s);
	min = find_min(s);
	if (value < s.stack[min])
	{
		if (count_to_top(s, min, direction)
			< count_to_top(s, find_min(s), direction))
			return (count_to_top(s, min, direction));
		return (count_to_top(s, find_min(s), direction));
	}
	if (value > s.stack[max])
		return (handle_max(s, direction));
	return (-1);
}
