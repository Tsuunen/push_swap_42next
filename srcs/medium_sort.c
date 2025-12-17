/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:57:16 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 11:27:12 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	find_from_top(t_stack *a, int bucket_size, int k, int *dir)
{
	int		tmp;
	size_t	i;

	i = 0;
	tmp = 0;
	while (i < a->size)
	{
		if (a->stack[i] >= k * bucket_size
			&& a->stack[i] < (k + 1) * bucket_size)
		{
			tmp = i;
			*dir = 0;
			break ;
		}
		i++;
	}
	return (tmp);
}

int	find_from_bot(t_stack *a, int bucket_size, int k, int *dir)
{
	int		tmp;
	size_t	i;

	i = a->size - 1;
	tmp = 0;
	while (i >= 0)
	{
		if (a->stack[i] >= k * bucket_size
			&& a->stack[i] < (k + 1) * bucket_size)
		{
			tmp = a->size - i;
			*dir = 1;
			break ;
		}
		i--;
	}
	return (tmp);
}

int	find_best(t_stack *a, int bucket_size, int k, int *dir)
{
	int	tmp1;
	int	tmp2;
	int	temp_dir;

	tmp1 = find_from_top(a, bucket_size, k, dir);
	tmp2 = find_from_top(a, bucket_size, k, &temp_dir);
	if (tmp2 < tmp1)
	{
		*dir = temp_dir;
		return (tmp2);
	}
	return (tmp1);
}

void	push_to_b(t_stack *a, t_stack *b, int *op_nbr)
{
	int	tmp;
	int	dir;

	while (b->size)
	{
		tmp = count_to_top(*b, find_max(*b), &dir);
		while (tmp--)
			universal_rotate(*b, dir, op_nbr);
		push(b, a, 1, op_nbr);
	}
}

void	medium_sort(t_stack *a, t_stack *b, int *op_nbr)
{
	int	bucket_size;
	int	k;
	int	tmp;
	int	dir;
	int	done;

	bucket_size = a->size / (ft_isqrt(a->size) / 2) + 1;
	if (normalize(a))
		return ;
	k = 0;
	done = 0;
	while (a->size)
	{
		tmp = find_best(a, bucket_size, k, &dir);
		while (tmp--)
			universal_rotate(*a, dir, op_nbr);
		push(a, b, 1, op_nbr);
		done++;
		if (!(done % bucket_size))
			k++;
	}
	push_to_b(a, b, op_nbr);
}
