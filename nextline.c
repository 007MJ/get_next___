#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

char	*thelie(char *line)
{
	
}

char	*get_next_line(int fd)
{
	char		*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	return (ft_theline(buff));

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
