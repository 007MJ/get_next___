/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_nex_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:03 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/01/10 12:42:10 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4

char	*get_next_line(int fd)
{
	char		*buff;
	int			i;

	i = 0;
	buff = (char *)malloc (BUFFER_SIZE + 1 * sizeof(char));
	while (0 < read(fd, buff, BUFFER_SIZE))
	{
		
		i++;
	}
	return (buff);
}

int	main(void)
{
	char *str;

	int	fd = open("filetest.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
