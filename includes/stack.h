/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:49 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:50:32 by nahecre          ###   ########.fr       */
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
int		s(t_stack s);
int		ss(t_stack a, t_stack b);
int		push(t_stack *from, t_stack *to);
int		rotate(t_stack s);
int		rotate_reverse(t_stack s);
int		shift_reverse(t_stack s);
int		shift(t_stack s);
int		count_to_top(t_stack s, int index, int *direction);
int		count_to_place(t_stack s, int value, int *direction);
int		count_to_place_reverse(t_stack s, int value, int *direction);
void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	print_stack(t_stack s);
int		find_max(t_stack s);
int		find_min(t_stack s);
int		universal_rotate(t_stack s, int direction);
void	rotate_both(t_stack a, t_stack b, int direction);
int		check_sort(t_stack *s);
int		max(int a, int b);
int		min(int a, int b);
int		is_in_stack(t_stack *s, int value);
float	compute_disorder(t_stack *a);
void	radix_sort(t_stack* a, t_stack* b);
void	radix_sort_remi(t_stack* a, t_stack* b);
int		check_sort_reverse(t_stack *s);
int		check_strict_sort(t_stack *s);
int		check_strict_sort_reverse(t_stack *s);
int		arg_parser(int argc, char **argv, t_stack *a, char *args);

#endif
