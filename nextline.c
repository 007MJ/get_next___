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

char	*ft_backslah(char *str)
{
	char	*strslah;
	int		i;

	i = 0;
	strslah = ft_strcalloc(ft_strlen(str), sizeof(char));
	while (str[i - 1] != '\n')
	{
		strslah[i] = str[i];
		i++;
	}
	//str = ft_onstatic(str, str + i);
	return (strslah);
}

char	*get_next_line(int fd)
{
	static char	*dststatic;
	char		*srcbuff;
	char		*temp;

	src = ft_strcalloc(BUFFER_SIZE, sizeof(char));
	read(fd, src, BUFFER_SIZE);
	while (read(fd, src, BUFFER_SIZE))
	{
		temp = ft_concante(dststatic, srcbuff);
		dst = temp;
	}

	free(temp);
	return (ft_backslah(dst));
}

char	*ft_concante(char *dst, char *src)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strcalloc(ft_strlen(src) + ft_strlen(dst) + 1, sizeof(char));
	if (dststatic == null)
	{
		while (dst[i])
		{
			tmp[i] = dst[i];
			i++;
		}
	}
	while (srcbuff[j])
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

// void	strcpy(char *dst, char *src)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }

// char	*ft_concante(char *dst, char *tmp, char src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (dst != NULL)
// 	{
// 		while (dst[i])
// 		{
// 			tmp[i] = dst[i];
// 			i++;
// 		}
// 	}
// 	while (src[i])
// 	{
// 		tmp[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	tmp[i] = '\0';
// 	return (tmp);
// }

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
