/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_complex_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:13:22 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:48:31 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	universal_rotate(t_stack s, int direction)
{
	if (!direction)
	{
		ft_printf("r%c\n", s.name);
		return (rotate(s));
	}
	ft_printf("rr%c\n", s.name);
	return (rotate_reverse(s));
}

void	rotate_both(t_stack a, t_stack b, int direction, int print)
{
	if (!direction)
	{
		if (print)
			ft_printf("rr\n");
		rotate(a);
		rotate(b);
	}
	else
	{
		if (print)
			ft_printf("rrr\n");
		rotate_reverse(a);
		rotate_reverse(b);
	}
}
