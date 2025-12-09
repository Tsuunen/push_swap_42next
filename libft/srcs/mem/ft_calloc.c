/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:09 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/06 11:23:51 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*out;
	long int	len;

	len = nmemb * size;
	if (len > INT_MAX)
		return (NULL);
	out = malloc(len);
	if (!out)
		return (NULL);
	ft_memset(out, 0, len);
	return (out);
}
