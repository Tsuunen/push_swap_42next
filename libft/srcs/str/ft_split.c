/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:25:45 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/06 09:54:18 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *src, int n)
{
	char	*output;
	int		i;

	output = malloc(n + 1);
	if (!output)
		return (0);
	i = 0;
	while (src[i] && i < n)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

static int	count_words(char *str, char c)
{
	int	count;
	int	i;
	int	new_word;

	count = 0;
	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] == c)
			new_word = 1;
		else
		{
			if (new_word)
			{
				new_word = 0;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static void	free_out(char **out, int i)
{
	while (i >= 0)
	{
		free(out[i]);
		i--;
	}
}

static int	manage_split(int wc, char *str, char c, char **out)
{
	int		i;
	char	*start;

	i = 0;
	while (i < wc)
	{
		if (*str == c)
			str++;
		else
		{
			start = str;
			while (*str != c && *str)
				str++;
			out[i] = ft_strndup(start, str - start);
			if (!out[i])
			{
				free_out(out, i);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**out;

	if (!s)
		return (NULL);
	word_count = count_words((char *) s, c);
	out = malloc(sizeof(*out) * (word_count + 1));
	if (!out)
		return (0);
	out[word_count] = NULL;
	if (manage_split(word_count, (char *) s, c, out))
	{
		free(out);
		return (NULL);
	}
	return (out);
}
