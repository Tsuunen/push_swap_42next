/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:13 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/10 14:02:01 by relaforg         ###   ########.fr       */
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
								t_stack *b)
{
	int	i;

	i = 0;
	bucket->sizes[bucket_index]++;
	ft_printf("Bucket_indexes : ");
	while (i < bucket->nbr)
	{
		if (i != bucket_index && bucket->indexes[i] != -1)
			bucket->indexes[i] = (bucket->indexes[i] + 1) % b->size;
		ft_printf("%d ", bucket->indexes[i]);
		i++;
	}
	if (bucket->indexes[bucket_index] == -1)
		bucket->indexes[bucket_index] = 0;
	ft_printf("\n");
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
	while (a->size)
	{
		bucket_index = (a->stack[0] - bucket.min) * bucket.nbr / (bucket.max - bucket.min + 1);
		if (bucket_index >= bucket.nbr)
			bucket_index = bucket.nbr - 1;
		tmp = count_to_top(*b, bucket.indexes[bucket_index], &dir);
		i = 0;
		while (i++ < tmp)
			universal_rotate(*b, dir);
		if (tmp > 0)
			update_bucket_indexes_rotation(&bucket, b, dir, tmp);
		push(a, b);
		update_bucket_indexes_push(&bucket, bucket_index, b);
	}
	free(bucket.indexes);
	free(bucket.sizes);
}
