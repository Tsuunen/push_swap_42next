/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:21:56 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 13:47:37 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	int			size;
	char		*buf;

	va_start(ap, fmt);
	size = parse_fmt(ap, NULL, fmt);
	va_end(ap);
	buf = ft_calloc(size, sizeof(*buf));
	if (!buf)
		return (-1);
	va_start(ap, fmt);
	parse_fmt(ap, buf, fmt);
	va_end(ap);
	if (write(fd, buf, size) < 0)
		size = -1;
	free(buf);
	return (size);
}
