/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_nex_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:03 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/01/17 14:52:56 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 2

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*csrc ;
	char	*cdest ;

	csrc = (char *)src;
	cdest = (char *)dst;
	i = 0;
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (cdst > csrc)
	{
		while (len > 0)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(cdst, csrc, len);
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lengh1;
	int		lengh2;
	char	*c_s1;

	lengh1 = ft_strlen(s1);
	lengh2 = ft_strlen(s2);
	c_s1 = malloc ((lengh1 + lengh2) + 1 * sizeof(*s1));
	if (!c_s1)
		return (NULL);
	ft_memmove((void *)c_s1, s1, lengh1);
	i = 0;
	while (i < lengh2)
	{
		c_s1[lengh1] = s2[i];
		i++;
		lengh1++;
	}
	c_s1[lengh1] = '\0';
	return (c_s1);
}


char	*get_next_line(int fd)
{
	char		*buff;
	char		*str;
	char		*tallstr;
	int			i;

	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	str = (char *)malloc (BUFFER_SIZE + 1 * sizeof(char));
	tallstr = (char *)malloc(BUFFER_SIZE * sizeof(char));
	i = 0;
	while (0 < read(fd, buff, BUFFER_SIZE))
	{
		i = 0;
		str[0] = '\0';
		while (i < BUFFER_SIZE)
		{
			str[i] = buff[i];
			i++;
			ft_strjoin(tallstr, str);
			if (buff[i] == '\n')
				return (tallstr);
		}
	}
	return ("don't work");
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = 0;
	fd = open("filetest.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}

