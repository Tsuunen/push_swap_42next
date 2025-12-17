/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:49 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 13:15:43 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include "libft.h"

typedef struct s_stack
{
	int		*stack;
	size_t	size;
	char	name;
}	t_stack;

int		swap(t_stack s);
int		ss(t_stack a, t_stack b, int print, int *op_nbr);
int		push(t_stack *from, t_stack *to, int print, int *op_nbr);
int		rotate(t_stack s);
int		rotate_reverse(t_stack s);
int		shift_reverse(t_stack s);
int		shift(t_stack s);
int		count_to_top(t_stack s, int index, int *direction);
void	simple_sort(t_stack *a, t_stack *b, int *op_nbr);
void	medium_sort(t_stack *a, t_stack *b, int *op_nbr);
int		find_max(t_stack s);
int		find_min(t_stack s);
int		universal_rotate(t_stack s, int direction, int *op_nbr);
void	rotate_both(t_stack a, t_stack b, int direction, int print);
int		check_sort(t_stack *s);
int		is_in_stack(t_stack *s, int value);
float	compute_disorder(t_stack *a);
void	radix_sort(t_stack* a, t_stack* b, int *op_nbr);
int		check_strict_sort(t_stack *s);
int		check_strict_sort_reverse(t_stack *s);
int		arg_parser(int argc, char **argv, t_stack *a, char *args);
int		normalize(t_stack *s);
void	bring_min_to_top(t_stack *a, int *op_nbr);

#endif
