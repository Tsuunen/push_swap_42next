/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:21:31 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 14:35:36 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

#define SIMPLE 1
#define MEDIUM 2
#define COMPLEX 4
#define BENCH 16
#define ADAPTATIVE 8

int check_params2(char *args, char *argv)
{
	if (!ft_strncmp(argv, "--adaptive", 11))
	{
		*args &= BENCH;
		*args |= ADAPTATIVE;
		return (1);
	}
	else if (!ft_strncmp(argv, "--bench", 8))
	{
		*args |= BENCH;
		return (1);
	}
	return (0);
}

int	check_params(char *args, char *argv)
{
	if (!ft_strncmp(argv, "--simple", 9))
	{
		*args &= BENCH;
		*args |= SIMPLE;
		return (1);
	}
	else if (!ft_strncmp(argv, "--medium", 9))
	{
		*args &= BENCH;
		*args |= MEDIUM;
		return (1);
	}
	else if (!ft_strncmp(argv, "--complex", 10))
	{
		*args &= BENCH;
		*args |= COMPLEX;
		return (1);
	}
	else
		return (check_params2(args, argv));
	return (0);
}

int	arg_parser(int argc, char **argv, t_stack *a, char *args)
{
	int	i;
	char	*end;
	(void) args;

	i = 1;
	*args = ADAPTATIVE;
	while (i < argc)
	{
		if (!check_params(args, argv[i]))
		{
			a->stack[a->size] = ft_strtoi(argv[i], &end);
			if (*end || is_in_stack(a, a->stack[a->size]))
				return (1);
			a->size++;
		}
		i++;
	}
	return (0);
}
