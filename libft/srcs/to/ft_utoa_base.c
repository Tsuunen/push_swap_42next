/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:20:10 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/10 13:06:45 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_number(unsigned int nbr, size_t base_len)
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

char	*ft_utoa_base(unsigned int n, char *base)
{
	int		size;
	char	*out;

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
