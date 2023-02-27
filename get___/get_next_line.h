/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:05:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/27 11:25:35 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
void	*ft_strdup(char *str);
char	*ft_concante(char *dst, char *src, int *stop);
char	*get_next_line(int fd);
char	*ft_srch_backn(char *src);
char	*ft_afterslahn(char *src, int i);
char	*ft_memmove(char *dst, const char *src, size_t len);
char	*ft_memcpy(char *dst, const char *src, size_t n);
char	*strmalloc(int size);
//char	*ft_newstatic(char *dst, char *src);

#endif
