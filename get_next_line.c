

/*   [recherchede fd]
 *
 *  input:(int fd, t_line **begin)
 *       On reherche si il exeiste un fd corespondant
 *       on retourne l'elementen question, on le malloc si nesessaire
 *  output:(t_line *elem)
 * */

t_line *search_fd(t_line **begin, int fd)
{
    t_line  *elem;

    if (!begin)
	return (NULL);
    elem = *begin;
    while (elem && elem->fd != fd)
	elem = elem->next;
    if (!elem)
    {
	elem = (t_line*) malloc(sizeof(t_line));
	if (!elem)
	    return (NULL);
	elem->fd = fd;
	elem->next = *begin;
	*begin = elem;
    }
    return (elem);
}

 
/*  [ajout de fd]
 *	
 *  input:(int fd, t_line **begin)
 *	Si on fd n'existe pas on l'ajoute au debut si la liste est vide
 *  output:(t_line *elem)
 * */
      
/*  [recherche de ligne '\0'] 
 *	
 *  input:()
 *	un simple str_chr
 *  output:()
 * */


/*  [empillage de lecture]
 *
 *  input:(int fd)
 *	on empile auttan de cache qu'ilfaut (tant qu'on a pas trouver de'\0')
 *	on fait sa dans une liste normale 
 *
 *
 *  output:(t_list *begin_cache)
 * */

t_list	*reading_stack(int fd)
{
    t_list  *begin;
    t_list  *elem;
    char    str[BUFF_SIZE + 1];
    int	    ret;

    ret = read(fd, str, BUFF_SIZE);
    str[ret] = '\0';
    elem = ft_creat_elem(str, ret);
    while(strchr(str, ))
    {
	;
    }
    return (begin);
}


/*  [malloc de chaine fraiche]
 *  
 *  input:(t_line *elem_1, t_list *begin_stack)
 *	on malloc d'un bloc la ligne et on copie ce qui doit etre copier
 *	donc il faut conter le nombre de catracter a alouer + alloc + memvmov
 *  output:()
 * */


/*  [mise a jour]
 *  
 *  input:()
 *	la c'est un peu le grand netoyage
 *	-on fait un mememove de str sur line si il contenanitune ligne entirer
 *	-on copie le reste du buffere si on a eu besoin de lire plus
 *	-on libere le maillon si il n'ya plus rien a lire (fin du fd)
 *	-on libere la liste temporaire si elle a ete utilise
 *  output:()
 * */

Femmeboutiquone
int
get_next_line(const int fd, char **line);
int get_next_line(int fd, char **line)
{
    static  *t_line lst_fd = NULL;

    return (1);
}
