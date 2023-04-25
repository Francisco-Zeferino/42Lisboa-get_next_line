/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:04:58 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/25 17:00:32 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	char		*str;
	static char	*line;
	int			bytes;

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

char	*next_line(char *line)
{
	char	*str;
	char	*file_next_line;
	int		str_len;

	if (ft_strchr(line, '\n'))
	{
		file_next_line = ft_strchr(line, '\n');
		str_len = ft_strlen(file_next_line);
		str = (char *)malloc(str_len + 1);
		if (str == NULL)
			return (0);
		str[str_len] = '\0';
		ft_strlcpy(str, file_next_line, str_len);
	}
	else
	{
		str_len = ft_strlen(line) - 1;
		str = (char *)malloc(str_len + 1);
		if (str == NULL)
			return (0);
		ft_strlcpy(str, line, str_len);
		str[str_len] = '\0';
	}
	return (str);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s_next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd);
	if (!line)
		return (NULL);
	s_next_line = next_line(line);
	line = new_line(line);
	return (line);
}

int	main(void)
{
	int fd, i;
	i = 5;
	fd = open("file.txt", O_RDONLY);
	while (i > 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
}
