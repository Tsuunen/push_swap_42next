/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:24:49 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/08 11:25:39 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_number(unsigned long nbr, size_t base_len)
{
	int		size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		size++;
		nbr /= base_len;
	}
	return (size);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	int			size;
	char		*out;

	if (!base)
		return (NULL);
	size = get_digit_number(n, ft_strlen(base));
	out = ft_calloc(size + 1, sizeof(*out));
	if (!out)
		return (NULL);
	if (n == 0)
		out[0] = '0';
	while (n)
	{
		out[--size] = base[(n % ft_strlen(base))];
		n /= ft_strlen(base);
	}
	return (out);
}
