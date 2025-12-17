/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:21:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 13:22:17 by relaforg         ###   ########.fr       */
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

int	s(t_stack s, int op_nbr[11])
{
	if (swap(s))
		return (1);
	ft_printf("s%c\n", s.name);
	if (op_nbr)
	{
		if (s.name == 'a')
			op_nbr[0]++;
		else if (s.name == 'b')
			op_nbr[1]++;
	}
	return (0);
}

int	ss(t_stack a, t_stack b, int print, int op_nbr[11])
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
	if (op_nbr)
		op_nbr[2]++;
	return (0);
}

int	push(t_stack *from, t_stack *to, int print, int *op_nbr)
{
	if (!from->size)
		return (1);
	if (to->size > 0)
		to->stack[to->size] = shift(*to);
	to->stack[0] = from->stack[0];
	to->size += 1;
	shift_reverse(*from);
	from->size -= 1;
	if (print)
		ft_printf("p%c\n", to->name);
	if (op_nbr)
	{
		if (to->name == 'a')
			op_nbr[3]++;
		else if (to->name == 'b')
			op_nbr[4]++;
	}
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
