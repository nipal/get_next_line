/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_labo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:54:25 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/23 04:36:02 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct				s_dfile
{
//	struct	s_dfile			*next_fd;
//	struct	s_dfile			*next_str;
	int						fd;
	int						i;
	int						size;
	char					*str;
}							t_dfile;

# define BUFF_SIZE 10

#include <stdio.h>

void	describe_dfile(t_dfile elem)
{
	dprintf(1, "");
}


int	main(void)
{
	static	t_dfile	tab[BUFF_SIZE];
	int		i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		dprintf(1, "->%d	i:%ld	", i, (long)(tab + i));
		dprintf(1, "fd:%d	i:%d	size:%d	str:|%s|\n", tab[i].fd, tab[i].i, tab[i].size, tab[i].str);
		i++;
	}
		dprintf(1, "%ld\n", (long)sizeof(t_dfile));
	return (0);
}

t_list	*copy_line_and_free_lst(t_list *elem, char **dest)
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
	// la la mamoir est copier dans la ligne a envoier
	if (ft_strlen((char*)(elem->content + i)))
	{
		stmp = ft_strdup((char*)(elem->content) + i);
		free(elem->content);
		elem->content = stmp;
		return (elem);
	}
	else
	{

	}
	return (tmp);
}
