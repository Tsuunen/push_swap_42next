/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:34:09 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/09 09:51:45 by nahecre          ###   ########.fr       */
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
		< count_to_top(s, find_max_reverse(s), direction))
		tmp = count_to_top(s, max, direction);
	else
		tmp = count_to_top(s, find_max_reverse(s), direction);
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
			< count_to_top(s, find_min_reverse(s), direction))
			return (count_to_top(s, min, direction));
		return (count_to_top(s, find_min_reverse(s), direction));
	}
	if (value > s.stack[max])
		return (handle_max(s, direction));
	return (-1);
}

int	count_to_place_reverse(t_stack s, int value, int *direction)
{
	int	tmp;
	int	min;

	if (s.size < 2)
		return (0);
	tmp = manage_minmax_reverse(s, value, direction);
	if (tmp != -1)
		return (tmp);
	tmp = 0;
	min = s.size;
	while ((size_t) tmp < s.size)
	{
		if (value <= s.stack[tmp]
			&& value >= s.stack[(tmp - 1 + s.size) % s.size])
			if (min > count_to_top(s, tmp, direction))
				min = count_to_top(s, tmp, direction);
		tmp++;
	}
	return (min);
}
