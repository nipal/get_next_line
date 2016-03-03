/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:16:22 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/03 05:13:55 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *mem, size_t size)
{
	unsigned	char	*memc;
	unsigned	char	**memcc;

	memcc = (unsigned char**)mem;
	memc = *memcc;
	ft_bzero(mem, size);
	free(mem);
	*mem = NULL;
}
