/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 00:31:20 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **begin, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (begin)
	{
		while (*begin)
		{
			tmp = (*begin)->next;
			ft_lstdelone(&begin, del);
			*begin = tmp;
		}
	}
}
