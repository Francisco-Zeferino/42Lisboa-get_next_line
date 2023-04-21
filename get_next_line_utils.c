/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:52:41 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/21 12:54:07 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_file_line(int fd, char *line)
{
	char	*store_text;
	size_t	bytes;

	store_text = (char *)malloc(BUFFER + 1);
	if (store_text == NULL)
		return (0);
	bytes = 1;
	while (!ft_strchr(line, '\n'))
	{
		bytes = read(fd, store_text, BUFFER);
		if (fd == -1)
		{
			free(store_text);
			return (NULL);
		}
		store_text[bytes] = '\0';
		line = ft_strjoin(line, store_text);
	}
	free(store_text);
	return (line);
}

char add_next_line(char *line)
{
	char str;
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
		{
			return (0);
		}
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_str1;
	int		len_str2;
	int		total_len;

	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	total_len = len_str1 + len_str2;
	new_str = (char *)malloc(total_len + 1);
	if (new_str == NULL)
	{
		return (0);
	}
	ft_strlcpy(new_str, s1, len_str1 + 1);
	ft_strlcpy(new_str + len_str1, s2, len_str2 + 1);
	return (new_str);
}