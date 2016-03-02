/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/02 09:06:44 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned	char	*cp_dest;
	unsigned	char	*cp_src;

	if (!dest || !src)
		return (NULL);
	cp_dest = (unsigned char*)dest;
	cp_src = (unsigned char*)src;
	if (cp_src < cp_dest)
	{
		i = -1;
		while (++i < n)
			cp_dest[i] = cp_src[i];
	}
	else
	{
		i = n;
		while (i-- > 0)
			cp_dest[i] = cp_src[i];
	}
	return ((void*)dest);
}
