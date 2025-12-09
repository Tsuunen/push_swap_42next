/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:50:05 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/07 12:09:58 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_number(long int nbr, size_t base_len)
{
	int		size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr)
	{
		size++;
		nbr /= base_len;
	}
	return (size);
}

char	*ft_itoa_base(int n, char *base)
{
	long int	nbr;
	int			size;
	char		*out;

	if (!base)
		return (NULL);
	nbr = (long int) n;
	size = get_digit_number(nbr, ft_strlen(base));
	out = ft_calloc(size + 1, sizeof(*out));
	if (!out)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		out[0] = '-';
	}
	if (nbr == 0)
		out[0] = '0';
	while (nbr)
	{
		out[--size] = base[(nbr % ft_strlen(base))];
		nbr /= ft_strlen(base);
	}
	return (out);
}
