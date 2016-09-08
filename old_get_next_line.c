/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:02:25 by fjanoty           #+#    #+#             */
/*   Updated: 2016/09/06 05:44:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


/*
 *	-la fonction qui reunni deux chaine de caractere
 *	-la fonction qui empile les buffer avec un reste et qui le remet bien
 * */

int	ft_strmchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (0);
	if (c == 0)
		return (ft_strlen(s));
	p = ft_strchr(s, c);
	if (p)
		dprintf(1, "strmchr:%d\n", (int)(p - s));
	return (0);
}

char		*ft_str_magic(char *str1, char *str2)
{
	int		max1;
	int		max2;
	char	*result;

	if (!str1 || !str2)
	{
		dprintf(1, "too baaad str1=[%d] and str2=[%d]\n", (str1 != NULL), (str2 != NULL))
		return (NULL);
	}
	max1 = ft_strmchr(str1, '\n');
	max2 = ft_strmchr(str2, '\n');


	if (!(result = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	ft_strcat(result, str1);
	ft_strncat(result + ft_strlen(str1), str2, n);
	return (result);
}


char		*ft_strnjoinfree(char *str1, char *str2)
{
	int		i;
	int		j;
	int		size1;
	int		size2;
	char	*sum;

	int		max1;
	int		max2;

//#	dprintf(1, "wesh	1\n");
	if (!str1)
		dprintf(1, "====	no srt1\n");
	if (!str2)
		dprintf(1, "====	no srt2\n");
	if (!str1 || !str2)
		return (NULL);
	max1 = ft_strmchr(str1, '\n');
	max2 = ft_strmchr(str2, '\n');
//#	dprintf(1, "wesh	2\n");
//	n = (n >= 0) ? n : BUFF_SIZE;
//#	dprintf(1, "wesh	3\n");
	size1 = max1;//ft_strlen(str1);
	size2 = max2;//ft_strlen(str1);
//#	dprintf(1, "wesh	4\n");
//	size2 = ft_strlen(str2);
//#	dprintf(1, "wesh	5\n");
	if (!(sum = ft_strnew(size1 + size2)))
		return (NULL);
//#	dprintf(1, "wesh	6\n");
	i = -1;
//#	dprintf(1, "i:%d	str:%ld	str[i]:%d\n", i, (long)str1, (int)str1[i]);
	while ((i++ + 10) && str1 && str1[i])
		sum[i] = str1[i];
	j = -1;
//#	dprintf(1, "i:%d	str:%ld	str[i]:%d\n", j, (long)str2, (int)str2[i]);
	while ((j++ + 10) && str2 && str2[j])
	{
		dprintf(1, "nonnn\n");
		sum[i + j] = str1[j];
	}
//	ft_memmove(sum, str1, ft_strlen(str1));
//#	dprintf(1, "wesh	7\n");
//	ft_memmove(sum + size1, str2, n);
//#	dprintf(1, "wesh	8\n");
//	free(str1);
//	free(str2);
	if (!sum)
		dprintf(1, "ou lala sum y a va pas bien\n");
	return (sum);
}

/*
**	on recupere le reste comme si on venait de le voir
**	on cherche si il y a un '\n'
**		si oui on recupere le reste du buffer on le savgarde
**		si non on relis le buffer
*/

char	*str_line2(int fd, char **rest)
{
	int		again;
	int		ret;
	char	*line;
	char	*buffer;
	char	*tmp;

	line = ft_strnew(BUFF_SIZE);
	buffer = ft_strnew(BUFF_SIZE);
	ft_memmove(buffer, *rest, MIN(ft_strlen(*rest), BUFF_SIZE));
	if (ft_strchr(buffer, '\n')/*il y a un /n dans line*/)
		again = 0;
	else
		again = 1;
	again = (!(ft_strchr(buffer, '\n')));
	//	la on fait la boucle normal
//	ret = read(de, buffer, BUFF_SIZE);
	line = ft_strnew(BUFF_SIZE);
	buffer = ft_strnew(BUFF_SIZE);
//	line[0] = 'a';line[1] = 'b';buffer[0] = 'c';buffer[1] = 'd';
	while (again == 1 /*pas de \n dans buffer et pas la fin du read*/)
	{
		ret = read(fd, buffer, BUFF_SIZE);
//#		dprintf(1, "line____i:%d	str:%ld	str[i]:%d\n", 0, (long)line, (int)line[0]);
//#		dprintf(1, "buffer__i:%d	str:%ld	str[i]:%d\n", 0, (long)buffer, (int)buffer[0]);
	//	tmp = ft_strnjoinfree(line,  buffer, BUFF_SIZE);
		tmp = ft_str_magic(line, buffer);
		line = tmp;
//#		dprintf(1, "@@@>	[%s]\n", tmp);
//		dprintf(1, ">>>	[%s]\n", line);
		//	on recupere la chaine de caractere
		again = ((!(ft_strchr(buffer, '\n'))) && ret > 0);
//		dprintf(1, "buffer:	[%s]\n", buffer);
//		dprintf(1, "sum:	[%s]\n", line);
		if (!line)
			dprintf(1, "ou lala sum y a va pas bien\n");
	}
	//
//#	dprintf(1, "non\n");
//	ft_memmove(*rest, buffer, MIN(ft_strlen(buffer), ft_strlen(*rest)));
//#	dprintf(1, "oui\n");
//#	dprintf(1, "$$>	[%s]\n", line);
//	dprintf(1, "sum2:	[%s]\n", line);
	return (line);
}



/*
**	On va faire le realloc
**		tan que on ne trouve pas de \n ou EOF
*/

int	get_next_line(int fd, char **line)
{
	//	static	char *buff = NULL;
//	int	ret;
	char	*rest = "";
	char	*str;

//	dprintf(1, "the fd:	%d\n", fd);
	if (fd < 0 || !line)
		return (-1);
//	dprintf(1, "youpi--1\n");
	str = str_line2(fd, &rest);
//#	dprintf(1, "==>	[%s]\n", str);
//	dprintf(1, "youpi--2\n");
//	dprintf(1, "the line:	[%s]", str);
//#	dprintf(1, "youpi--3\n");
//	ft_memmove(*line, str, ft_strlen(str));
//#	dprintf(1, "youpi--4\n");
	*line = str;
	return (ft_strlen(str) > 0);
}

