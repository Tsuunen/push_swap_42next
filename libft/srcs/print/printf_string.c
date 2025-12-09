/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:19:54 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 10:22:15 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_string(char *str, char *buf)
{
	size_t		len;
	const char	null_str[7] = "(null)";

	if (!str)
		str = (char *) null_str;
	len = ft_strlen(str);
	if (buf)
		ft_memcpy(buf, str, len);
	return ((int) len);
}
