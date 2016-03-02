/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/24 23:57:40 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (s && f)
	{
		i = 0;
		new = ft_strnew(ft_strlen(s));
		ft_strcpy(new, s);
		while (new[i])
		{
			new[i] = f(i, new[i]);
			i++;
		}
	}
	else
		return (NULL);
	return (new);
}
