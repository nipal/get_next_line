/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_testdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:12:16 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/03 05:41:13 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*put_lst_str(t_list	**begin)
{
	int		i;
	t_list	*elem;
	t_list	*prev;
	t_list	*prev2;

	i = 0;
	prev = NULL;
	prev2 = NULL;
	elem = *begin;
			dprintf(1, "Ho HO HO\n");
	if (elem)
	{
		while (elem->next)
		{
			prev2 = prev;
			prev = elem;
			dprintf(1, "Hu Hu Hu\n");
			if (elem && elem->content)
				dprintf(1, "1)i:%d=>	%s :: %ld\n", i, (char*)elem->content, (long)elem->content);
			dprintf(1, "Hi Hi Hi\n");
			i++;
			elem = elem->next;
		}
		if (elem && elem->content)
			dprintf(1, "2)i:%d=>	%s :: %ld\n", i, (char*)elem->content, (long)elem->content);
		if (prev2)
			prev2->next = NULL;
		ft_lstdel(begin, &ft_del);
	}
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
begin =	put_lst_str(&begin);
	put_lst_str(&begin);
	put_lst_str(&begin);
begin =	put_lst_str(&begin);
	put_lst_str(&begin);
	put_lst_str(&begin);
	put_lst_str(&begin);
	return (0);
}
