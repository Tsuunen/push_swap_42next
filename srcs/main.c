/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 12:55:07 by relaforg         ###   ########.fr       */
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

void	adaptative_sort(t_stack *a, t_stack *b)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder < 0.5)
		medium_sort(a, b);
	else
		radix_sort(a, b);
}

void	launch_sort(t_stack *a, t_stack *b, char args)
{
	if (args & 1)
		simple_sort(a, b);
	else if ((args >> 1) & 1)
		medium_sort(a, b);
	else if ((args >> 2) & 1)
		radix_sort(a, b);
	else if ((args >> 3) & 1)
		adaptative_sort(a, b);
	if ((args >> 4) & 1)
		ft_printf("bench\n");
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
	arg_parser(argc, argv, &a, &args);
	// printf("%f\n", compute_disorder(a));
	launch_sort(&a, &b, args);
	free(a.stack);
	free(b.stack);
	return (0);
}
