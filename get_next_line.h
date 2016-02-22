/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/22 15:14:47 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

# define BUFF_SIZE 2
# define TARGET_CHAR '\n'
# define DESTROY 1
# define CLEAN 2
# define COPY 4



# define NAME_FT				0

# define DEBUG					1
# define DEBUG_MANIP_BRANCH		1
# define DEBUG_CREAT_DFILE		1
# define DEBUG_GET_RIGHT_FD		1
# define DEBUG_GET_LINE			1
# define DEBUG_GET_NEXT_LINE	1

//		::::	MANIP_BRANCH	::::
# define PRINT_WRONG_FD			1
# define PRINT_NEW_FD			1
# define PRINT_COPY_SIZE		1


//		::::	CREAT_DFILE 	::::
# define PRINT_ELEM				1


//		::::	GET_RIGHT_FD	::::


//		::::	GET_LINE    	::::
# define PRINT_RESULT			0


//		::::	GET_NEXT_LINE	::::
# define PRINT_RETURN 			0 


//		::::	PRINT_DFILE 	::::
# define PRINT_VALID			0
# define PRINT_NEXT_FD			0
# define PRINT_NEXT_STR			0
# define PRINT_FD				0
# define PRINT_I				0
# define PRINT_SIZE				0
# define PRINT_STR				0
# define PRINT_STAGE			0

typedef	struct				s_dfile
{
	struct s_dfile			*next_fd;
	struct s_dfile			*next_str;
	int						fd;
	int						i;
	int						size;
	char					*str;
	int						stage;
}							t_dfile;
int							get_next_line(int const fd, char **line);
#endif

//	Flag de debugging
//		-un par fonction
//
