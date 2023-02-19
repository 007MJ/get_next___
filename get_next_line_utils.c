/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:53:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/18 08:23:43 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_onstatic(char *strstatic)
{
	char	*newstatic;
	int		i;

	i = 0;
	newstatic = ft_strcalloc(ft_strlen(strstatic), sizeof(char));
	while (strstatic[i])
	{
		newstatic[i] = strstatic[i];
		i++;
	}
	//free(&strstatic);
	print(newstatic);
	newstatic[i] = '\0';
	return (newstatic);
}

