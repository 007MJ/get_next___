#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

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

char	*ft_strjoin(char const *s1, char const *s2, int *stop)
{
	int		i;
	int		lengh1;
	int		lengh2;
	char	*c_s1;

	lengh1 = ft_strlen(s1);
	lengh2 = ft_strlen(s2);
	c_s1 = malloc ((lengh1 + lengh2) + 1 * sizeof(char *));
	if (!c_s1)
		return (NULL);
	ft_memmove((void *)c_s1, s1, lengh1);
	i = 0;
	while (i < lengh2)
	{
		c_s1[lengh1] = s2[i];
		if (s2[i] == '\n')
		{
			*stop = 1;
			break ;
		}
		i++;
		lengh1++;
	}
	c_s1[lengh1] = '\0';
	return (c_s1);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*str;
	// int				*stop;
	int				i;

	i = 0;
	// stop = &i;
	buff = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	str = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	while (i != 1)
	{
		// printf("%d", i);
		read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff, &i);
		// printf("%s", buff);
		// break;
		// printf("%d", 1);
	}
	// str[0] = '0';
	return (str);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("note.txt", O_RDONLY);
		str = get_next_line(fd);
		printf("%s", str);
		str = get_next_line(fd);
		printf("%s", str);
}
