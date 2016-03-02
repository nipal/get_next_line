/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 01:52:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
 *	si on copy le dernier element, on peut utiliser lstdel
 * */
static	char	*copy_line_and_free_lst(t_list *elem, char **dest, int nb_last)
{
	int		rest;
	int		i;
	t_list	*tmp;
	char	*stmp;

	rest = 0;
	while (elem->next)
	{
		tmp = elem->next;
		ft_memcopy(*dest + rest, (char*)elem->content, BUFF_SIZE);
		rest += BUFF_SIZE;
		free(elem->content);
		free(elem);
		elem = tmp;
	}
	i = ((strchr((char*)elem->content), TARGET_CHAR) - (char*)elem->content);
	ft_memcopy(*dest + rest, elem->content, (size_t)i);
	stmp = (ft_strlen((char*)(elem->content + i))) ? ft_strdup((char*)((elem->content + i))) : NULL;
	free(elem->content);
	return = (stmp);
}

static	t_list	*fill_line(t_list *begin, int fd)
{
	t_list	*elem;
	int		i;

	elem = begin;
	if (elem && !elem->content)
	{
		elem->content = malloc(sizeof(char) * BUFF_SIZE);
		elem->content_size = 0;
	}
	while (elem)
	{
		elem->content_size += read(fd, elem->content, BUFF_SIZE - elem->content_size);
		if ((i = (ft_strchr((char*)elem->content, TARGET_CHAR) - elem->content)) < 0)
			//	on a pas touver de \n
		else if (i < 0 && elem->content_size != BUFF_SIZE)
			//	on est a la fin du fichier et on a trouver de \n
		else
			//	on a trouver un \n
	}
}

int	get_next_line(int const fd, char **line)
{
}


/*
 *	on recupere le reste de la chaine, on remplis ce qui manque
 *		tan que on et pas a la fin de la chaine: (FIN BUFFER)
 *			(on cherce un \n)	=>	si on a un buffer plein et qu'on en a ps trouver on recommence
 *
 *
 * */
