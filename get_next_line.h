/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:05:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/23 17:01:47 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 71

int		ft_strlen(char *str);
void	*ft_strcalloc(int count, size_t size);
char	*ft_concante(char *dst, char *src, int *stop);
char	*get_next_line(int fd);
char	*ft_onstatic(char *onstatic);
void	print(char *str);
char	*ft_srch_backn(char *src);
char	*ft_strchr(char *s, int c);
char	*ft_afterslahn(char *src, int i);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
//char	*ft_newstatic(char *dst, char *src);

#endif
