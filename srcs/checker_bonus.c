/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:15:03 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 14:24:19 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	manage_op(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "sa", 3))
		swap(*a);
	else if (!ft_strncmp(op, "sb", 3))
		swap(*b);
	else if (!ft_strncmp(op, "ss", 3))
		ss(*a, *b, 0, NULL);
	else if (!ft_strncmp(op, "pa", 3))
		push(b, a, 0, NULL);
	else if (!ft_strncmp(op, "pb", 3))
		push(a, b, 0, NULL);
	else if (!ft_strncmp(op, "rra", 4))
		rotate_reverse(*a);
	else if (!ft_strncmp(op, "rrb", 4))
		rotate_reverse(*b);
	else if (!ft_strncmp(op, "rrr", 4))
		rotate_both(*a, *b, 1, 0);
	else if (!ft_strncmp(op, "ra", 3))
		rotate(*a);
	else if (!ft_strncmp(op, "rb", 3))
		rotate(*b);
	else if (!ft_strncmp(op, "rr", 3))
		rotate_both(*a, *b, 0, 0);
	else
		return (1);
	return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*op;

	op = get_next_line(0);
	while (op && *op)
	{
		op[ft_strlen(op) - 1] = 0;
		if (manage_op(a, b, op))
		{
			free(op);
			return (1);
		}
		free(op);
		op = get_next_line(0);
	}
	return (0);
}

int	alloc_stack(t_stack *a, t_stack *b, int argc)
{
	a->stack = ft_calloc(argc - 1, sizeof(int));
	if (!a->stack)
		return (1);
	b->stack = ft_calloc(argc - 1, sizeof(int));
	if (!b->stack)
	{
		free(a->stack);
		return (1);
	}
	a->size = 0;
	b->size = 0;
	return (0);
}

void	free_quit(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	ft_dprintf(2, "Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	args;

	if (argc <= 1)
		return (0);
	if (alloc_stack(&a, &b, argc))
		return (1);
	if (arg_parser(argc, argv, &a, &args))
		free_quit(&a, &b);
	if (checker(&a, &b))
		free_quit(&a, &b);
	if (check_strict_sort(&a) && !b.size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a.stack);
	free(b.stack);
	return (0);
}
