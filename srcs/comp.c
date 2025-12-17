/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:33:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 13:13:44 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
