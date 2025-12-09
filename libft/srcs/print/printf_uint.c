/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:52:12 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 10:22:24 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_uint(unsigned int nbr, char *buf)
{
	char	*str;
	size_t	len;

	str = ft_utoa(nbr);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (buf)
		ft_memcpy(buf, str, len);
	free(str);
	return (len);
}
