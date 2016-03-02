/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/23 00:16:45 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (src < dest)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char*)dest) = (unsigned char)*src;
			dest++;
			src++;
			i++;
		}
	}
	else if (dest < src)
	{
		i = n - 1;
		while (i < n)
		{
			*((unsigned char*)dest) = (unsigned char)*src;
			dest++;
			src++;
			i++;
		}
	}
	return (dest);
}
