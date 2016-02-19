/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/19 08:47:29 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h> 
# include <fcntl.h>
# define BUFF_SIZE 32
# define TARGET_CHAR '\n'
# define SIZE_BUFF ((BUFF_SIZE > 0 || BUFF_SIZE > 2147483647) ? BUFF_SIZE : 32)
# define DESTROY 1
# define CLEAN 2

typedef	struct				s_dfile
{
	struct	s_dfile			*next_fd;
	struct	s_dfile			*next_str;
	int						fd;
	int						i;
	int						size;
	char					*str;
}							t_dfile;
int							get_next_line(int const fd, char ** line);
#endif
