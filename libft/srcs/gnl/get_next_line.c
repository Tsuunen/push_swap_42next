/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:56:02 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/21 17:29:04 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*fill_res(char *buf, char *res, char *nl)
{
	int	res_size;

	res_size = ft_strlen(res);
	if (res)
		res = ft_realloc(res, res_size + 1, (res_size + (nl - buf) + 2)
				* sizeof(*res));
	else if (buf[0])
		res = ft_realloc(res, res_size + 1, (nl - buf + 2) * sizeof(*res));
	if (!res)
		return (NULL);
	ft_strlcpy(res + res_size, buf, (nl - buf) + 2);
	ft_strlcpy(buf, nl + 1, BUFFER_SIZE + 1);
	return (res);
}

static int	update_read(char *buf, char **res, int fd)
{
	int	read_size;

	if (buf[0])
	{
		*res = fill_res(buf, *res, buf + ft_strlen(buf) - 1);
		if (!*res)
			return (MALLOC_FAIL);
	}
	ft_bzero(buf, BUFFER_SIZE + 1);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size < 0)
	{
		free(*res);
		return (MALLOC_FAIL);
	}
	else if (read_size == 0)
		return (SUCCESS);
	buf[read_size] = 0;
	return (CONTINUE);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*res;
	char		*nl;
	int			err;

	if (fd >= OPEN_MAX || fd < 0)
		return (NULL);
	res = NULL;
	nl = ft_strchr(buf[fd], '\n');
	while (!nl)
	{
		err = update_read(buf[fd], &res, fd);
		if (err == MALLOC_FAIL)
			return (NULL);
		else if (err == SUCCESS)
			return (res);
		nl = ft_strchr(buf[fd], '\n');
	}
	res = fill_res(buf[fd], res, nl);
	return (res);
}
