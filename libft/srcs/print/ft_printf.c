/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:21:56 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 10:21:39 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	manage_option(va_list ap, char opt, char *buf)
{
	if (opt == 'c')
		return (printf_char(va_arg(ap, int), buf));
	else if (opt == 's')
		return (printf_string(va_arg(ap, char *), buf));
	else if (opt == 'd' || opt == 'i')
		return (printf_int(va_arg(ap, int), buf));
	else if (opt == 'u')
		return (printf_uint(va_arg(ap, unsigned int), buf));
	else if (opt == 'x')
		return (printf_xint((long) va_arg(ap, int), buf));
	else if (opt == 'X')
		return (printf_xint_up(va_arg(ap, int), buf));
	else if (opt == '%')
		return (printf_percent(buf));
	else if (opt == 'p')
		return (printf_pointer(va_arg(ap, void *), buf));
	return (0);
}

int	parse_fmt(va_list ap, char *buf, const char *fmt)
{
	int		size;
	int		tmp;

	size = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			tmp = manage_option(ap, *(++fmt), buf);
			if (buf)
				buf = buf + tmp;
			size += tmp;
		}
		else
		{
			if (buf)
				*buf++ = *fmt;
			size++;
		}
		fmt++;
	}
	return (size);
}

int	ft_printf(const char *fmt, ...)
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
	if (write(1, buf, size) < 0)
		size = -1;
	free(buf);
	return (size);
}
