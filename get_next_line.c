/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 04:45:39 by fjanoty          ###   ########.fr       */
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
		//	on a pas touver de \n mais il reste de truc a lire dans le fichier
		//	donc il faut un nouveau chainonx avec unnouveau buffer et un curseur (buff_size)
		if ((i = (ft_strchr((char*)elem->content, TARGET_CHAR) - (char*)elem->content)) < 0
				&& elem->content_size == BUFF_SIZE)
		{
			(!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (NULL);
			str[BUFF_SIZE] = '\0';
			elem->next = ft_lstnew(str, 0);
			elem = elem->next;
		}

		// 	Si	(on est a la fin du fichier) ET (on a pas trouver de \n)
		else if (i < 0)
		{
			//	la le travaille est terminer ET on connai la taille du dernier bufer
			//	qui est enregistre dans le content_size
			//	donc juste un return begin
			return (begin);
		}

		//	on a trouver un \n. Donc on a plus besoin d'accumuller de nouvaux buffer.
		else
		{
			return (begin);
		}
	}
	return (begin);
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
