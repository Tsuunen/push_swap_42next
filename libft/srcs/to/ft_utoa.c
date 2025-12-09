/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:53:27 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/10 13:06:09 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_number(long int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	long int	nbr;
	int			size;
	char		*out;

	nbr = (long int) n;
	size = get_digit_number(nbr);
	out = ft_calloc(size + 1, sizeof(*out));
	if (!out)
		return (NULL);
	if (nbr == 0)
		out[0] = '0';
	while (nbr)
	{
		out[--size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (out);
}
