/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:37 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/05 11:58:50 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;

	out = malloc((ft_strlen(s) + 1) * sizeof(*out));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, ft_strlen(s) + 1);
	return (out);
}
