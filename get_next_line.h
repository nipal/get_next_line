/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/22 08:00:54 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

# define BUFF_SIZE 100
# define TARGET_CHAR '\n'
# define DESTROY 1
# define CLEAN 2
# define COPY 4





# define DEBUG					1	//DONE
# define DEBUG_MANIP_BRANCH		1	//DONE
# define DEBUG_CREAT_DFILE		1	//DONE
# define DEBUG_GET_RIGHT_FD		1
# define DEBUG_GET_LINE			1	//DONE
# define DEBUG_GET_NEXT_LINE	1	//DONE

//		::::	MANIP_BRANCH	::::
# define PRINT_WRONG_FD			1
# define PRINT_NEW_FD			1


//		::::	CREAT_DFILE 	::::
# define PRINT_ELEM				1


//		::::	GET_RIGHT_FD	::::


//		::::	GET_LINE    	::::


//		::::	GET_NEXT_LINE	::::
# define PRINT_RETURN 			1


//		::::	PRINT_DFILE 	::::
# define PRINT_VALID			1
# define PRINT_NEXT_FD			1
# define PRINT_NEXT_STR			1
# define PRINT_FD				1
# define PRINT_I				1
# define PRINT_SIZE				1
# define PRINT_STR				1

typedef	struct				s_dfile
{
	struct s_dfile			*next_fd;
	struct s_dfile			*next_str;
	int						fd;
	int						i;
	int						size;
	char					*str;
}							t_dfile;
int							get_next_line(int const fd, char **line);
#endif

//	Flag de debugging
//		-un par fonction
//
