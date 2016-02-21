/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/21 02:59:27 by fjanoty          ###   ########.fr       */
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
# define DESTROY 1
# define CLEAN 2
# define COPY 4

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


//static	t_dfile		*creat_dfile(int fd, t_dfile *next_fd)					:	DONE
//static	void		free_branche(t_dfile *elem, t_dfile *prev, int mode)	:	DONE
//static	t_dfile		*get_right_fd(t_dfile **lst, int fd, t_dfile **prev)	:	DONE
//static	char		*get_line(t_dfile *begin, int *error)					:	
//int					get_next_line(int const fd, char **line)				:	
