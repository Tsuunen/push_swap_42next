/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:33:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:18:09 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_in_stack(t_stack *s, int value)
{
	size_t	i;

	i = 0;
	while (i < s->size)
	{
		if (s->stack[i] == value)
			return (1);
		i++;
	}
	return (0);
}
