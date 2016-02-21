/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/21 04:46:22 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_dfile	*creat_dfile(int fd, t_dfile *next_fd)
{
	t_dfile	*elem;
	
	elem = (t_dfile*)malloc(sizeof(t_dfile));
	if (!elem)
		return (NULL);
	elem->next_fd = next_fd;
	elem->next_str = NULL;
	elem->i = 0;
	elem->str = (char*)malloc(sizeof(SIZE_BUFF + 1));
	if (!elem->str)
		return (NULL);
	if ((elem->size = read(fd, elem->str, SIZE_BUFF)) < 0)
		return (NULL);
	else if (elem->size != BUFF_SIZE)
		elem->size += read(fd, elem->(str + elem->size), BUFF_SIZE - elem->size)
	(elem->str)[elem->size] = '\0';
}

//	on peu utiliser la branche de trois manier:
//		-on suprime toute une branche
//		-on vide tout j'usqu'a l'avant dernier maillon 
//		on copy la chaine du maillon sur une chaine de caaractere
//

//	DONE
static	void	manip_branche(int mode, t_dfile *elem, t_dfile *prev, char *copy)
{
	t_dfile	*tmp;

	if (mode == DESTROY)
		prev->next_fd = elem->next_fd;
	while (elem && ((mode != CLEAN) || (elem->next_fd)))
	{
		tmp = elem->next_fd;
		while (mode == COPY && *elem->str++)
			*(copy++) = *(elem->str - 1);
		if ((elem->next && mode == CLEAN) || mode == DESTROY)
		{
			free(elem->str);
			free(elem);
		}
		else if (mode == COPY)
			tmp = elem->next_char;
		elem = tmp;
	}
	if (mode == CLEAN && elem)
		prev->next_fd = elem;
}

//	DONE
static	t_dfile	*get_right_fd(t_dfile **lst, int fd, t_dfile **prev)
{
	t_dfile	*elem;

	elem = *lst;
	while (elem && elem->id != fd)
	{
		*prev = elem;
		elem = elem->next_fd;
	}
	if (!elem)
	{
		elem = creat_dfile(fd, *lst);
		if (!elem)
			return (NULL);
		*lst = elem;
	}
	return (elem);
}

static	int		get_line(t_dfile *elem, t_dfile *prev, char **line, int *error)
{
	char	*str;
	t_dfile	*elem;
	int		nb_char;

	str = elem->(str + elem->i);
	while (*str && *str != TARGET_CHAR)
	{
		while (*str && *str != TARGET_CHAR)
			str++;
		nb_char += str - (elem->str - elem->i);
		if (!(*str) && elem->size == (BUFF_SIZE))
		{
			if (!(elem->next_char = creat_dfile(elem->fd, elem->next_fd)))
				return ((*(error  = -1)));
			str = elem->(str + elem->i);
		}
	}
	if ((*line = malloc(sizeof(char) * (nb_char + 1))))
		return (((*error = -1) * 0));
	manip_branche(COPY, elem, prev, *line);
	manip_branche(CLEAN, elem, prev, 0);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	t_dfile			*prev;
	int				error;

	prev = NULL;
	elem = get_right_fd(&lst, fd, &prev);
	if ((get_line(elem, prev, line, &error) != 1))
		return (error);
	return (1);
}
