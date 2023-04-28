/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:04:58 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/27 11:13:05 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_empty_ln(char *line)
{
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
	return (line);
}

char	*check_error(char *line, int bytes)
{
	if (bytes == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_line(int fd, char *line)
{
	char	*str;
	int		bytes;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (0);
	bytes = 1;
	line = check_empty_ln(line);
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			free(line);
			line = NULL;
			return (0);
		}
		str[bytes] = '\0';
		line = ft_strjoin(line, str);
	}
	free(str);
	line = check_error(line, bytes);
	return (line);
}

static char	*next_line(char *line)
{
	char	*str;
	char	*str_f;
	int		str_len;

	if (!ft_strchr(line, '\n'))
		str_f = line + ft_strlen(line) - 1;
	else
		str_f = ft_strchr(line, '\n');
	str_len = str_f - line + 1;
	str = (char *)malloc(str_len + 1);
	if (str == NULL)
	{
		free(line);
		free(str);
		return (0);
	}
	str[str_len] = '\0';
	ft_memmove(str, line, str_len);
	ft_memmove(line, str_len + line, ft_strlen(line) - str_len + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s_next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line);
	if (!line)
		return (NULL);
	s_next_line = next_line(line);
	return (s_next_line);
}
