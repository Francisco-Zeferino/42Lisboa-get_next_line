
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER 100
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	get_file_line(int fd, char *line);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
