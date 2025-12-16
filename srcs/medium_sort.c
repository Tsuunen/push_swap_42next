/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:13 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 11:56:57 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

typedef struct s_bucket
{
	int *indexes;
	int	*sizes;
	int nbr;
	int	min;
	int	max;
}	t_bucket;

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

int	init_bucket(t_bucket *bucket, t_stack *a)
{
	int	i;

	i = 0;
	bucket->nbr = ft_isqrt(a->size);
	bucket->min = a->stack[find_min(*a)];
	bucket->max = a->stack[find_max(*a)];
	bucket->indexes = ft_calloc(bucket->nbr, sizeof(int));
	if (!bucket->indexes)
		return (1);
	bucket->sizes = ft_calloc(bucket->nbr, sizeof(int));
	if (!bucket->sizes)
	{
		free(bucket->indexes);
		return (1);
	}
	while (i < bucket->nbr)
	{
		bucket->indexes[i] = -1;
		i++;
	}
	return (0);
}

void	update_bucket_indexes_rotation(t_bucket *bucket, t_stack *b, int dir,
									int steps)
{
	int	i;

	i = 0;
	while (i < bucket->nbr && b->size)
	{
		if (dir && bucket->indexes[i] != -1)
			bucket->indexes[i] = (bucket->indexes[i] + steps) % b->size;
		else if (bucket->indexes[i] != -1)
			bucket->indexes[i] = (bucket->indexes[i] - steps + b->size) % b->size;
		i++;
	}
}

void	update_bucket_indexes_push(t_bucket *bucket, int bucket_index,
								t_stack *b, int value_pushed)
{
	int	i;
	int	old_max_pos;

	i = 0;
	while (i < bucket->nbr)
	{
		if (i != bucket_index && bucket->indexes[i] != -1)
			bucket->indexes[i] = (bucket->indexes[i] + 1) % b->size;
		i++;
	}
	bucket->sizes[bucket_index]++;
	if (bucket->sizes[bucket_index] == 1)
		bucket->indexes[bucket_index] = 0;
	else
	{
		old_max_pos = (bucket->indexes[bucket_index] + 1) % b->size;

		if (value_pushed > b->stack[old_max_pos])
			bucket->indexes[bucket_index] = 0;
		else
			bucket->indexes[bucket_index] = old_max_pos;
	}
}

int	find_insert_position_in_bucket(t_stack *b, int bucket_start, int bucket_size, int value)
{
	int	pos;
	int	i;

	if (bucket_size == 0)
		return (bucket_start);
	i = 0;
	while (i < bucket_size)
	{
		pos = (bucket_start + i) % b->size;
		if (b->stack[pos] < value)
			return (pos);
		i++;
	}
	return ((bucket_start + bucket_size) % b->size);
}

void	medium_sort(t_stack *a, t_stack *b)
{
	t_bucket	bucket;
	int			bucket_index;
	int			tmp;
	int			dir;
	int			i;

	if (init_bucket(&bucket, a))
		return ;
	while (a->size && !check_sort(a))
	{
		bucket_index = (a->stack[0] - bucket.min) * bucket.nbr / (bucket.max - bucket.min + 1);
		if (bucket_index >= bucket.nbr)
			bucket_index = bucket.nbr - 1;
		if (bucket.sizes[bucket_index] != 0)
		{
			tmp = find_insert_position_in_bucket(b, bucket.indexes[bucket_index], 
										bucket.sizes[bucket_index], a->stack[0]);
			tmp = count_to_top(*b, tmp, &dir);
			i = 0;
			while (i++ < tmp)
				universal_rotate(*b, dir);
			if (tmp > 0)
				update_bucket_indexes_rotation(&bucket, b, dir, tmp);
		}
		tmp = a->stack[0];
		push(a, b, 1);
		update_bucket_indexes_push(&bucket, bucket_index, b, tmp);
	}
	while (b->size)
	{
		tmp = count_to_place_reverse(*a, b->stack[0], &dir);
		while (tmp--)
			universal_rotate(*a, dir);
		push(b, a, 1);
	}
	tmp = count_to_top(*a, find_min(*a), &dir);
	while (tmp--)
		universal_rotate(*a, dir);
	free(bucket.indexes);
	free(bucket.sizes);
}
