/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_testdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:12:16 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 10:08:49 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*put_lst_str(t_list	*begin)
{
	int		i;
	t_list	*elem;
	t_list	*prev;

	i = 0;
	elem = begin;
	while (elem->next)
	{
		prev = elem;
		printf("i:%d=>	%s\n", i, (char*)elem->content);
		i++;
		elem = elem->next;
	}
	printf("i:%d=>	%s\n", i, (char*)elem->content);
	prev->next = NULL;
	ft_lstdel(&begin, &ft_del);
	return (elem);
}



int	main(int ac, char **av)
{
	t_list	*begin;
	int		i;

	i = 2;
	begin = ft_lstnew(av[1], ft_strlen(av[1]) * sizeof(char));
	while (i < ac)
	{
		ft_lstaddend(&begin, ft_lstnew(av[i], ft_strlen(av[i]) * sizeof(char)));
		i++;
	}
	begin = put_lst_str(begin);
	put_lst_str(begin);
	return (0);
}
