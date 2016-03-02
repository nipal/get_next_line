/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/25 00:42:48 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;

	copy = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 && s2)
	{
		if (!copy)
			return (NULL);
		copy = ft_strcpy(copy, s1);
		copy = ft_strcat(copy, s2);
	}
	return (copy);
}
