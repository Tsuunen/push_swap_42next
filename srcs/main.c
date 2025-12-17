/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 14:36:01 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include <stdio.h>

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
}

void	adaptative_sort(t_stack *a, t_stack *b, int *op_nbr, float disorder)
{
	if (disorder < 0.2)
		simple_sort(a, b, op_nbr);
	else if (disorder < 0.5)
		medium_sort(a, b, op_nbr);
	else
		radix_sort(a, b, op_nbr);
}

int	launch_sort(t_stack *a, t_stack *b, char args)
{
	int		*op_nbr;
	float	disorder;

	op_nbr = ft_calloc(11, sizeof(int));
	if (!op_nbr)
		return (1);
	disorder = compute_disorder(a);
	if (args & 1)
		simple_sort(a, b, op_nbr);
	else if ((args >> 1) & 1)
		medium_sort(a, b, op_nbr);
	else if ((args >> 2) & 1)
		radix_sort(a, b, op_nbr);
	else if ((args >> 3) & 1)
		adaptative_sort(a, b, op_nbr, disorder);
	if ((args >> 4) & 1)
		print_bench(op_nbr, disorder, args);
	free(op_nbr);
	return (0);
}

void	free_exit(t_stack *a, t_stack *b, int print)
{
	free(a->stack);
	free(b->stack);
	if (print)
		ft_dprintf(2, "Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	args;

	a.stack = ft_calloc(argc - 1, sizeof(int));
	if (!a.stack)
		return (1);
	b.stack = ft_calloc(argc - 1, sizeof(int));
	if (!b.stack)
	{
		free(a.stack);
		return (1);
	}
	init_stacks(&a, &b);
	if (arg_parser(argc, argv, &a, &args))
		free_exit(&a, &b, 1);
	if (!a.size)
		free_exit(&a, &b, 0);
	if (launch_sort(&a, &b, args))
		free_exit(&a, &b, 1);
	free(a.stack);
	free(b.stack);
	return (0);
}
