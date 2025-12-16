/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:37:13 by nahecre          ###   ########.fr       */
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
	radix_sort_remi(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
