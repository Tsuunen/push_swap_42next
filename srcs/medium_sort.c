/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:57:16 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 11:06:43 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_isqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i - 1);
}

void	medium_sort(t_stack *a, t_stack *b, int *op_nbr)
{
	int nbr_bucket;
	int bucket_size;
	int	k;
	size_t	i;
	int	tmp;
	int	dir;
	int	done;

	nbr_bucket = ft_isqrt(a->size) / 2;
	bucket_size = a->size / nbr_bucket + 1;
	if (normalize(a))
		return ;
	k = 0;
	done = 0;
	while (a->size && k < nbr_bucket)
	{
		i = 0;
		while (i < a->size)
		{
			if (a->stack[i] >= k * bucket_size
				&& a->stack[i] < (k + 1) * bucket_size)
			{
				tmp = i;
				dir = 0;
				break ;
			}
			i++;
		}
		i = a->size - 1;
		while (i >= 0 && (size_t) tmp > a->size - i)
		{
			if (a->stack[i] >= k * bucket_size
				&& a->stack[i] < (k + 1) * bucket_size)
			{
				tmp = a->size - i;
				dir = 1;
				break ;
			}
			i--;
		}
		while (tmp--)
			universal_rotate(*a, dir, op_nbr);
		push(a, b, 1, op_nbr);
		done++;
		if (done >= bucket_size)
		{
			done = 0;
			k++;
		}
	}
	while (b->size)
	{
		tmp = count_to_top(*b, find_max(*b), &dir);
		while (tmp--)
			universal_rotate(*b, dir, op_nbr);
		push(b, a, 1, op_nbr);
	}
}
