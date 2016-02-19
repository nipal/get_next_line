/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/19 19:05:37 by fjanoty          ###   ########.fr       */
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

//	on peu netoyer la branche de deux manier:
//		-on suprime toute une branche
//		-on vide tout j'usqu'a l'avant dernier maillon 

static	void	free_branche(t_dfile *elem, t_dfile *prev, int mode)
{
	t_dfile	*tmp;

	if (mode == DESTROY)
	{
		prev->next_fd = elem->next_fd;
		while(elem)
		{
			tmp = elem->next;
			free(elem->str);
			free(elem);
			elem = tmp;
		}
	}
	else if (mode == CLEAN && elem)
	{
		while(elem->next)
		{
			tmp = elem->next;
			free(elem->str);
			free(elem);
			elem = tmp;
		}
		prev->next_fd = elem;
	}
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

//	on lis la str a partir de l'indice jusque:
//		|1| fin du fichier
//		|2| caracter fin de ligne

//		-(tite verife pour voir si on est vraiment a la fin du fichier)->creat
//	
//	 
//		-on malloc une chaine la bonne taille
//		-on redefini lindice
//		-on copie tout les buffer different
//	|1|	-on free en mode destroy
//	|2|	-on free en mode clean
static	char	*get_line(t_dfile *begin, int *error)
{
	char	*str;
	t_dfile	*elem;
	int		nb_char;

	str = begin->(str + begin->i);

	while (*str && *str != TARGET_CHAR)
		str++;
}

int	get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	t_dfile			*prev;
	int				error;

	prev = NULL;
	elem = get_right_fd(&lst, fd, &prev);
	
	return (1);
}
