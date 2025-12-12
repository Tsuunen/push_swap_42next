/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:23:46 by nahecre           #+#    #+#             */
/*   Updated: 2025/12/12 13:09:42 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

float	compute_disorder(t_stack a)
{
	int		mistakes;
	int		total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a.size)
	{
		j = i + 1;
		while (j < a.size)
		{
			total_pairs++;
			if (a.stack[i] > a.stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
