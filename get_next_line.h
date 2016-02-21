/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:50:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/21 14:53:04 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 2
# define TARGET_CHAR '\n'
# define DESTROY 1
# define CLEAN 2
# define COPY 4

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
