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
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strline(char *src)
{
	static char	*dst;
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
		strline[lenght] = src [i];
		if (src[i] == '\n')
			return (strline);
		i++;
		lenght++;
	}
	return ("DON'T WORK !");
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

