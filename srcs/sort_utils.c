/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:54:20 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 13:15:16 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	count_to_top(t_stack s, int index, int *direction)
{
	int	from_bot;

	from_bot = s.size - index;
	if (from_bot < index)
	{
		*direction = 1;
		return (from_bot);
	}
	*direction = 0;
	return (index);
}

int	min_handler(t_stack s, int *direction)
{
	int	min;
	int	tmp;

	min = find_min(s);
	if (min == 0)
	{
		*direction = 0;
		return (1);
	}
	if (count_to_top(s, min, direction)
		< count_to_top(s, find_min(s), direction))
		tmp = count_to_top(s, min, direction);
	else
		tmp = count_to_top(s, find_min(s), direction);
	if (*direction == 0)
		return (tmp + 1);
	return (tmp - 1);
}

int	manage_minmax(t_stack s, int value, int *direction)
{
	int	max;
	int	min;

	max = find_max(s);
	min = find_min(s);
	if (value > s.stack[max])
	{
		if (count_to_top(s, max, direction)
			< count_to_top(s, find_max(s), direction))
			return (count_to_top(s, max, direction));
		return (count_to_top(s, find_max(s), direction));
	}
	if (value < s.stack[min])
		return (min_handler(s, direction));
	return (-1);
}
