/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:07:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print(char *str)
{
	printf("%s", str);
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

char	*ft_backslahn(char *str)
{
	char	*strslah;
	int		i;

	i = 0;
	print(str);
	strslah = ft_strcalloc(ft_strlen(str), sizeof(char));
	while (str[i])
	{
		strslah[i] = str[i];
		//printf("%c", strslah[i]);
		if (strslah[i] == '\n')
			print("ici");
		i++;
	}
	return ("////");
}

void	*ft_strcalloc(int count, size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc (count * sizeof(size));
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_concante(char *dst, char *src)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strcalloc(ft_strlen(src) + ft_strlen(dst) + 1, sizeof(char));
	if (dst != NULL)
	{
		while (dst[i])
		{
			tmp[i] = dst[i];
			i++;
		}
		free(dst);
	}
	while (src[j])
	{
		tmp[i] = src[j];
		//printf("%c", src[i]);
		if (src[j] == '\n')
			break ;
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*src;
	int			stop;
	int		readbit;

	stop = 1;
	readbit = 1;
	src = ft_strcalloc(BUFFER_SIZE, sizeof(char));
	while (readbit != 0)
	{
		readbit = read(fd, src, BUFFER_SIZE);
		dst = ft_concante(dst, src);
	}
	//free(dst);
	return (dst);
}
