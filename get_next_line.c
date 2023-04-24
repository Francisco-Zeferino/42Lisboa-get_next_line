/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:04:58 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/24 16:38:19 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	char		*str;
	static char	*line;
	size_t		bytes;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (0);
	bytes = 1;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
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
	return (line);
}

char	next_line(char *line)
{
	char	*str;
	int		*str_f;
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
	ft_strlcpy(str, line, str_len);
	ft_strlcpy(line, line + str_len, ft_strlen(line) - str_len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
}

// int	main()
// {
// 	int	fd;
// 	fd = open("file.txt", O_RDONLY);
// 	printf("%s\n",get_line(fd));
// }
