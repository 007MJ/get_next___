#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	ft_put_static(char *dst, char *src)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		dst[ii] = src[i];
		i++;
		ii++;
	}
	dst[i] = '\0';
}

char	*ft_strline(char *src)
{
	char		*dst;
	int			i;
	int			lenght;
	char		*strline;

	i = 0;
	lenght = 0;
	strline = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src)) + 1);
	while (src[i])
	{
		if (ft_strlen(dst) != 0)
		{
			*strline = *dst;
			strline++;
			dst++;
			lenght = ft_strlen(strline) - 1;
		}
		strline[lenght] = src[i];
		if (src[i - 1] == '\n')
		i++;
		lenght++;
	}
	return ("Don't work !");
}

char	*get_next_line(int fd)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);

	read(fd, buff, BUFFER_SIZE);
	return (ft_strline(buff));

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

