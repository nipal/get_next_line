/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 08:11:21 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
 *	si on copy le dernier element, on peut utiliser lstdel
 * */
t_list	*copy_line(t_list *begin, char **dest)
{
	int		rest;
	int		i;
	t_list	*prev;
	t_list	*elem;

	rest = 0;
	elem = begin;
	if (elem)
	{
		while (elem->next)
		{
			prev = elem;
			ft_memcopy(*dest + rest, (char*)elem->content, elem->content_size);
			rest += elem->contetn_size;
			elem = elem->next;
		}
		i = ((strchr((char*)elem->content), TARGET_CHAR) - (char*)elem->content);
		ft_memcopy(*dest + rest, elem->content, (size_t)i);
		ft_memmove(elem->content, elem-content + i);
		if (elem->content == BUFF_SIZE)
			prev->next = NULL;
		elem->content_size -= i;
		ft_lstdel(begin);
	}
	return = (elem);// si on a free elem il faut remvyer null
}

t_list	*fill_line(t_list *begin, int fd)
{
	t_list	*elem;
	int		i;
	char	*str;

	elem = begin;
	if (elem && !elem->content)
	{
		elem->content = malloc(sizeof(char) * BUFF_SIZE);
		elem->content_size = 0;
	}
	while (elem)
	{
		elem->content_size += read(fd, elem->content, BUFF_SIZE - elem->content_size);
		if ((i = (ft_strchr((char*)elem->content, TARGET_CHAR) - (char*)elem->content)) < 0
				&& elem->content_size == BUFF_SIZE)
		{
			(!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (NULL);
			str[BUFF_SIZE] = '\0';
			elem->next = ft_lstnew(str, 0);
		}
		elem = elem->next;
	}
	return (begin);
}

int	get_next_line(int const fd, char **line)
{
	static	t_list	fd_tab[NB_FD];

	fd_tab[fd] = fill_line(fd_tab + fd, fd);
	//	La il faudrait malloquer la ligne a la bonne taille
	//
	fd_tab[fd] = copie_line(fd_tab + fd, line, );
}


/*
 *	on recupere le reste de la chaine, on remplis ce qui manque
 *		tan que on et pas a la fin de la chaine: (FIN BUFFER)
 *			(on cherce un \n)	=>	si on a un buffer plein et qu'on en a ps trouver on recommence
 *
 *
 * */
