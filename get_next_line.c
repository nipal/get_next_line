p
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/19 03:39:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_dfile	*creat_dfile(int fd)
{
	t_dfile	*elem;
	
		elem = (t_dfile*)malloc(sizeof(t_dfile));
	if (!elem)
		return (NULL);
	elem->next_fd = *lst;
	elem->next_str = NULL;
	elem->i = 0;
	elem->str = (char*)malloc(sizeof(SIZE_BUFF + 1));
	if (!elem->str)
		return (NULL);
	if ((elem->size = read(fd, elem->str, SIZE_BUFF)) < 0 && *err = 1)
		return (NULL);
	(elem->str)[elem->size] = '\0';

}

//	si le fichier est terminer, on free tout
//	si le '\n' arrive a la fin du buffer...
//	si non on free tout sauf le dernier element
//	il faut aussi que en fresant les truc on garde les bon pointeur tout ca on peu faire une copie
static	void	free_branche_and_replace()
{
	
} 

static	t_dfile	*get_rignt_fd(t_dfile **lst, int fd, int *err)
{
	t_dfile	*elem;

	elem = *lst;
	while (elem && elem->id != fd)
		elem = elem->next_fd;
	if (!elem)
	{
		elem = (t_dfile*)malloc(sizeof(t_dfile));
		if (!elem)
			return (NULL);
		elem->next_fd = *lst;
		elem->next_str = NULL;
		elem->i = 0;
		elem->str = (char*)malloc(sizeof(SIZE_BUFF + 1));
		if (!elem->str)
			return (NULL);
		if ((elem->size = read(fd, elem->str, SIZE_BUFF)) < 0 && *err = 1)
			return (NULL);
		(elem->str)[elem->size] = '\0';
		*lst = elem;
	}
	return (elem);
}

static	char	*get_line(t_dfile *begin, int nb_char)
{
	char	*str;
	t_dfile	*elem;

	str = begin->(str + i);
	while (*str && *str != TARGET_CHAR)
		str++;
	while (!(*str))
	{
		// on a besoin d'un nouveau buffer
	}
	else
		// 	



}

int	get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	int				error;

	elem = get_rignt_fd(&lst, fd, &error, 0);
	
	return (1);
}



//	On	place l'element sur le bon fd
//		-si il n'y en a pas un cree un t_dfile, on remplis le buffeur, et on plas e curseur a 0

//	On cherche le premier '\n'	
