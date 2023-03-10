/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:07:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/25 10:47:45 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
		{
			i = i + 1;
			return ((char *)s + i);
		}
		i++;
	}
	if ((char )c == '\0')
		return ((char *)s + i);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (i);
}

char	*ft_concante(char *dst, char *src, int *stop)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(ft_strlen(src) + ft_strlen(dst) * sizeof(char) + 1);
	if (dst != NULL)
	{
		while (dst[i])
		{
			tmp[i] = dst[i];
			i++;
		}
		free(dst);
	}
	while (*src)
	{
		tmp[i] = *src;
		if (*src == '\n')
			*stop = 0;
		i++;
		src++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_srch_backn(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	while (j <= i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	src = ft_memmove(src, src + i + 1, ft_strlen(src + i + 1));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*src;
	int			stop;
	int			readbit;

	stop = 1;
	readbit = 1;
	src = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0)
		return (NULL);
	while (readbit != 0)
	{
		readbit = read(fd, src, BUFFER_SIZE);
		src[readbit] = 0;
		dst = ft_concante(dst, src, &stop);
		if (stop == 0)
		{
			break ;
		}
	}
	if (stop == 0)
		return (ft_srch_backn(dst));
	return (dst);
}
