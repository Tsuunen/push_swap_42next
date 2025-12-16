/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:21:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:31:59 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

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
