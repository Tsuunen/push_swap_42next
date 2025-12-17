/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 11:40:06 by nahecre          ###   ########.fr       */
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

void	print_stack(t_stack s)
{
	size_t	i;

	i = 0;
	ft_printf("[ ");
	while (i < s.size)
	{
		ft_printf("%d", s.stack[i++]);
		if (i < s.size)
			ft_printf(", ");
	}
	ft_printf(" ]\n");
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

int	compute_total_ops(int *op_nbr)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < 11)
	{
		s += op_nbr[i];
		i++;
	}
	return (s);
}

void	print_bench(int *op_nbr, float disorder, char args)
{
	ft_dprintf(2, "[bench] Disorder: %d.%d%%\n", (int) (disorder * 100),
			(int)(disorder * 10000) % 100);
	ft_dprintf(2, "[bench] Strategy: ");
	if (args & 1)
		ft_printf("Simple\n");
	else if ((args >> 1) & 1)
		ft_printf("Medium\n");
	else if ((args >> 2) & 1)
		ft_printf("Complex\n");
	else if ((args >> 3) & 1)
	{
		ft_printf("Adaptative / ");
		if (disorder < 0.2)
			ft_dprintf(2, "O(n²)\n");
		else if (disorder < 0.5)
			ft_dprintf(2, "O(n√n)\n");
		else
			ft_dprintf(2, "O(nlogn)\n");
	}
	ft_dprintf(2, "[bench] Total Ops: %d\n", compute_total_ops(op_nbr));
	ft_dprintf(2, "[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
			op_nbr[0], op_nbr[1], op_nbr[2], op_nbr[3], op_nbr[4]);
	ft_dprintf(2, "[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			op_nbr[5], op_nbr[6], op_nbr[7], op_nbr[8], op_nbr[9], op_nbr[10]);
}

int	launch_sort(t_stack *a, t_stack *b, char args)
{
	int	*op_nbr;
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
	{
		free(a.stack);
		free(b.stack);
		ft_dprintf(2, "Error\n");
		return (1);
	}
	if (launch_sort(&a, &b, args))
	{
		free(a.stack);
		free(b.stack);
		ft_dprintf(2, "Error\n");
		return (1);
	}
	free(a.stack);
	free(b.stack);
	return (0);
}
