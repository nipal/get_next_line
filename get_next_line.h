/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 07:31:59 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h> 
# include <fcntl.h>
# define BUFF_SIZE 32
# define NB_FD	1024
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
//static	void		manip_branch(t_dfile *elem, t_dfile *prev, int mode)	:	DONE
//static	t_dfile		*get_right_fd(t_dfile **lst, int fd, t_dfile **prev)	:	DONE
//static	char		*get_line(t_dfile *begin, int *error)					:	DONE
//int					get_next_line(int const fd, char **line)				:	DONE

// ON va essayer de separer manip branch en trois fonction de les regle aux ognion puis de le remerger

//	on lis sur le fd tan qu'il y a pas de '\0'
//		si on en rencontre on commence une liste chainer de la taille d'un buffer
//	temporairement on stoque la lecture dans une liste chainer && on conte le nombre de caractere stoque (size)
//

//	on remplis un fd
//	on remplis la line

//	on a une chaine malloccuer a la bone taille;
//	on a des list qui contiene ce qu'il faut
//

//	tant qu'on peu liredans la liste chainer on free tout sauf le dernier element
//
//	
