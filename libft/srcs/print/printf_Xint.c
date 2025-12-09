/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_Xint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:07:12 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 10:22:37 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_xint_up(int nbr, char *buf)
{
	size_t	len;
	char	*str;

	str = ft_utoa_base((unsigned) nbr, UP_HEX);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (buf)
		ft_memcpy(buf, str, len);
	free(str);
	return (len);
}
