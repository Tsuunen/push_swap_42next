/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:21:31 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/10 16:46:40 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

#define SIMPLE 1
#define MEDIUM 2
#define COMPLEX 4
#define BENCH 8

int	check_params(char *args, char *argv)
{
	if (!ft_strncmp(argv, "--simple", 9))
	{
		*args &= BENCH + SIMPLE;
		*args |= SIMPLE;
		return (1);
	}
	else if (!ft_strncmp(argv, "--medium", 9))
	{
		*args &= BENCH + MEDIUM;
		*args |= MEDIUM;
		return (1);
	}
	else if (!ft_strncmp(argv, "--complex", 10))
	{
		*args &= BENCH + COMPLEX;
		*args |= COMPLEX;
		return (1);
	}
	else if (!ft_strncmp(argv, "--bench", 8))
	{
		*args |= BENCH;
		return (1);
	}
	return (0);
}

int	arg_parser(int argc, char **argv, t_stack *a, char *args)
{
	int	i;
	char	*end;
	(void) args;

	i = 1;
	*args = 0;
	while (i < argc)
	{
		if (!check_params(args, argv[i]))
		{
			a->stack[i - 1] = ft_strtoi(argv[i], &end);
			if (*end || is_in_stack(*a, a->stack[i]))
				return (1);
			a->size++;
		}
		i++;
	}
	return (0);
}
