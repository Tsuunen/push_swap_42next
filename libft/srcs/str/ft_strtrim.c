/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:17:06 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/06 10:02:24 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*out;
	const char	*start;
	const char	*end;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == 0)
		return (ft_calloc(1, sizeof(char)));
	while (*s1 && is_in_set(*s1, set))
		s1++;
	start = s1;
	end = s1;
	while (*s1)
	{
		if (!is_in_set(*s1, set))
			end = s1 + 1;
		s1++;
	}
	out = ft_calloc(end - start + 1, sizeof(*out));
	if (!out)
		return (NULL);
	ft_strlcpy(out, start, end - start + 1);
	return (out);
}
