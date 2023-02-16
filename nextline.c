#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_concante(char *dst, char *src);

char	*ft_strmalloc(int size)
{
	
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*src;

	src = ft_strmalloc(BUFFER_SIZE);
	read(fd, src, BUFFER_SIZE);
	dst = ft_concante(dst, src);
	return (dst);
}

char	*ft_concante(char *dst, char *src)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strmalloc(ft_strlen(src) + ft_strlen(dst) + 1);
	if (dst != NULL)
	{
		while (dst[i])
		{
			tmp[i] = dst[i];
			i++;
		}
	}
	while (src[j])
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("note.txt", O_RDONLY);
		str = get_next_line(fd);
		printf("%s", str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// str = get_next_line(fd);
		// printf("%s", str);
}
