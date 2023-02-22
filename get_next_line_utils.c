/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:53:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:59 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backslahn(char *src, int i)
{
	char	*str;
	int		j;

	str = malloc (sizeof(char) * i + 1);
	j = 0;
	i = i + 1;
	while (src[i])
	{
		str[j] = src[i];
		i++;
		j++;
	}
	free(src);
	str[j] = '\0';
	printf("La static apres source : [%s]",str);
	return (str);
}
