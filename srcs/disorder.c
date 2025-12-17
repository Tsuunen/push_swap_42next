/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:23:46 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/17 15:40:43 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

float	compute_disorder(t_stack *s)
{
	int		mistakes;
	int		total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	if (s->size == 0 || s->size == 1)
		return (0);
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			total_pairs++;
			if (s->stack[i] > s->stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float) mistakes / total_pairs);
}
