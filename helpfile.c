#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
  int i;

  i = 0;
  while(str[i])
    i++;
  return (i);
}

char *slahinen(char *strn, char *strstill)
{
  char *newstatic;
  int i;

  i = 0;
  newstatic = malloc(sizeof(char) * ft_strlen(strstill));
  while (str)
}

char *ft_contante(char *dst, char *tmp, char *src, int *stop)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if (dst != NULL)
  {
    while (dst[i])
      {
        tmp[i] = dst[i];
        if (tmp[i] == '\n')
        {
            *stop = 0;
            break;
        }
        i++;
      }
  }
  while (src[j])
    {
      tmp[i] = src[j];
      if (tmp[i] == '\n')
          break;
      i++;
      j++;
    }
  tmp [i] = '\0';
  return (tmp);
}

int main(void) {
  char *dst;
  dst = "un bon matin commence \npar un 🥚";

  char tmp[100];

  char *src;
  src = "BONJOUR";

  int i;

  i = 1;
  printf("%s", ft_contante(dst, tmp, src, &i));
  int *adresse;
  adresse = &i;
  printf("%d", *adresse);
  return 0;
}
//==================================================the original ft_concante====================================================================
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

//==================================================the other ft_concante====================================================================
char	*ft_concante(char *dst, char *tmp, char *src, int *stop)
{
	if (dst != NULL)
	{
		while (*dst)
		{
			*tmp++ = *dst;
			if (*tmp == '\n')
			{
				*stop = 0;
				break ;
			}
			dst++;
			tmp++;
		}
	}
	while (*src)
	{
		//printf("%c", *src);
		*tmp = *src;
		//printf("%c", *src);
		printf("%c", *tmp);
		if (*tmp == '\n')
		{
			*stop = 0;
			break ;
		}
		src++;
		tmp++;
		//printf("%c", *tmp);
	}
	print(tmp);
	return ("Don't work right now");
}
