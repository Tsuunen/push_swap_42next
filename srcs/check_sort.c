/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:07:41 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 11:22:34 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_sort(t_stack s)
{
	int		max_found;
	size_t	i;

	i = 0;
	max_found = 0;
	while (i < s.size)
	{
		if (s.stack[i] > s.stack[(i + 1) % s.size])
		{
			if (max_found)
				return (0);
			max_found = 1;
		}
		i++;
	}
	return (1);
}

int	check_sort_reverse(t_stack s)
{
	int		max_found;
	size_t	i;

	i = 0;
	max_found = 0;
	while (i < s.size)
	{
		if (s.stack[i] < s.stack[(i + 1) % s.size])
		{
			if (max_found)
				return (0);
			max_found = 1;
		}
		i++;
	}
	return (1);
}

int	check_sort_strict(t_stack s)
{
	size_t	i;

	i = 0;
	while (i < s.size - 1)
	{
		if (s.stack[i] > s.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
