/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:43 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/02/25 10:45:16 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;




	fd = open("note.txt", O_RDONLY);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		str = get_next_line(-1);
		printf("%s", str);


}
