/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_nex_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:03 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/01/12 18:37:37 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../2klbf/libft/libft.h"

#define BUFFER_SIZE 10


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
	int			iread;

	i = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	str = (char *)malloc (BUFFER_SIZE + 1 * sizeof(char));
	tallstr = (char *)malloc(2 * sizeof(char));
	iread = 1;
	while (0 < iread)
	{
		iread = read(fd, buff, BUFFER_SIZE);
		while (buff[i])
		{
			str[i] = buff[i];
			i++;
		}
		ft_strjoin(tallstr, str);
		if (buff[i] == '\n' || buff[i] == '\0')
			return (tallstr);
	}
	return (NULL);
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
