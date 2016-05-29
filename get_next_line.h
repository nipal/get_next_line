/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/21 14:09:03 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
 
char	*ft_strchr(const char *s, int c);
//char	*ft_strnchr(const char *s, int c, int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
//void	ft_lstadd_end(t_list **alst, t_list *new);
t_list	*ft_lstnew(void const *content, size_t content_size);
 *
 * */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <lilbft.h>

# define BUFF_SIZE 10
# define TARGET '\0'

typedef	struct	s_line
{
    int	    fd;
    int	    size;
    char    str[BUFF_SIZE];
    struct  *s_line next;
}		t_line;


int get_next_line(const int fd, char **line);
#endif
