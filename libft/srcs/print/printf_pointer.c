/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:37 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 10:22:06 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_pointer(void *ptr, char *buf)
{
	size_t		len;
	char		*str;
	const char	null[6] = "(nil)";

	if (!ptr)
	{
		if (buf)
			ft_memcpy(buf, null, 5);
		return (5);
	}
	str = ft_ultoa_base((unsigned long) ptr, LOW_HEX);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (buf)
	{
		*buf++ = '0';
		*buf++ = 'x';
		ft_memcpy(buf, str, len);
	}
	free(str);
	return (len + 2);
}
