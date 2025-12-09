/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:21:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/09 12:28:52 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	swap(t_stack s)
{
	int	tmp;

	if (s.size < 2)
		return (1);
	tmp = s.stack[0];
	s.stack[0] = s.stack[1];
	s.stack[1] = tmp;
	return (0);
}

int	s(t_stack s)
{
	if (swap(s))
		return (1);
	ft_printf("s%c\n", s.name);
	return (0);
}

int	ss(t_stack a, t_stack b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return (1);
	if (to->size > 0)
		to->stack[to->size] = shift(*to);
	to->stack[0] = from->stack[0];
	to->size += 1;
	shift_reverse(*from);
	from->size -= 1;
	ft_printf("p%c\n", to->name);
	return (0);
}

int	rotate_reverse(t_stack s)
{
	if (s.size <= 0)
		return (1);
	s.stack[0] = shift(s);
	return (0);
}

int	rotate(t_stack s)
{
	if (s.size <= 0)
		return (1);
	s.stack[s.size - 1] = shift_reverse(s);
	return (0);
}
