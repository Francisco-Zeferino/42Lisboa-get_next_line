/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:52:41 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/27 09:43:55 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free((char *)s1);
	return (new_str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < ((unsigned)size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char		*pointer_dest;
	const unsigned char	*pointer_src;

	pointer_dest = (unsigned char *)dest;
	pointer_src = (const unsigned char *)src;
	if (pointer_dest == NULL && pointer_src == NULL)
	{
		return (NULL);
	}
	if (pointer_dest <= pointer_src)
	{
		while (n--)
			*pointer_dest++ = *pointer_src++;
	}
	else
	{
		pointer_dest += n;
		pointer_src += n;
		while (n--)
			*--pointer_dest = *--pointer_src;
	}
	return (dest);
}
