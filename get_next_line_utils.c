/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:53:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/23 16:56:38 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_afterslahn(char *src, int i)
{
	char	*str;
	int		j;

	str = malloc (sizeof(char) * i + 1);
	j = 0;
	printf("la taille du nouveau malloc %d", i);
	i = i + 1;
	while (src[i])
	{
		str[j] = src[i];
		i++;
		j++;
	}
	free(src);
	str[j] = '\0';
	//printf("La nouvelle static : [%s]",str);
	return (str);
}


// char	*ft_newstatic(char *dst, char *src)
// {
// 	// printf("la static : [%s] ",dst);
// 	// printf("la static apres le back : [%s] ",src);
// 	int i;
// 	char *str;

// 	i = 0;
// 	str = malloc (sizeof(char) * ft_strlen(src) + 1);
// 	while (src[i])
// 	{
// 		str[i] = src[i];
// 		i++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }
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
