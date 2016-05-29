/*
 *  on stoqe le reste des fd dans 
 *
 *  -on cherche si il y a deja un fd assosicer
 *	-si oui on cherche si il y reste une ligne
 *	    -si oui on malloc une chaine fraiche + return 1 + memmove sur lereste
 *	    -si non on empile la lecture puis on malloc la hainefraihe
 *	-si non on ajoute on maillon de fd et on empile la lecture
 *
 *
 *
 *libft:
 *
 *  ft_memmove()
 *  ft_lstaddback()
 *  ft_lstcreate_elem()
 *  ft_lst_delone()
 *  ft_lst_del_all()
 *  ft_strchr()
 *
 * */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define BUFF_SIZE 10
# define TARGET '\0'

typedef	struct	s_line
{
    int	    fd;
    char    str[BUFF_SIZE + 1];
    struct  *s_line next;
}		t_line;


int get_next_line(const int fd, char **line);
#endif
