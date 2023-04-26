/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:03:46 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/26 16:12:01 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 3
# endif

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, int size);
void	*ft_memmove(void *dest, const void *src, int n);

#endif
