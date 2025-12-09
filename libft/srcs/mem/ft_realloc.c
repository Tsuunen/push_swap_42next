/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:27:06 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/21 17:27:42 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t size)
{
	void	*res;

	if (!ptr)
		return (malloc(size));
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(size);
	if (!res)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr_size < size)
		ft_memmove(res, ptr, ptr_size);
	else
		ft_memmove(res, ptr, size);
	free(ptr);
	return (res);
}
