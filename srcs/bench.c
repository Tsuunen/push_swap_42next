/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:22:39 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/17 13:28:31 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	compute_total_ops(int *op_nbr)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < 11)
	{
		s += op_nbr[i];
		i++;
	}
	return (s);
}

void	print_bench(int *op_nbr, float disorder, char args)
{
	ft_dprintf(2, "[bench] Disorder: %d.%d%%\n", (int)(disorder * 100),
		(int)(disorder * 10000) % 100);
	ft_dprintf(2, "[bench] Strategy: ");
	if (args & 1)
		ft_dprintf(2, "Simple\n");
	else if ((args >> 1) & 1)
		ft_dprintf(2, "Medium\n");
	else if ((args >> 2) & 1)
		ft_dprintf(2, "Complex\n");
	else if ((args >> 3) & 1)
	{
		ft_dprintf(2, "Adaptative / ");
		if (disorder < 0.2)
			ft_dprintf(2, "O(n²)\n");
		else if (disorder < 0.5)
			ft_dprintf(2, "O(n√n)\n");
		else
			ft_dprintf(2, "O(nlogn)\n");
	}
	ft_dprintf(2, "[bench] Total Ops: %d\n", compute_total_ops(op_nbr));
	ft_dprintf(2, "[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
		op_nbr[0], op_nbr[1], op_nbr[2], op_nbr[3], op_nbr[4]);
	ft_dprintf(2, "[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		op_nbr[5], op_nbr[6], op_nbr[7], op_nbr[8], op_nbr[9], op_nbr[10]);
}
