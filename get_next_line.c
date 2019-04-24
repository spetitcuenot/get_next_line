/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 14:39:51 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 16:41:37 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

t_lgnl  *ft_lstsearchcreate(t_lgnl **lst, int fd)
{
    t_lgnl  *elem;
    t_lgnl  *tmp;
    tmp = *lst;
    if (*lst)
    {
        while (tmp && tmp->fd != fd)
        {
            if (tmp->fd == fd)
                return (tmp);
        tmp = tmp->next;
        }
    }
    if (!tmp)
    {  
        if (!(elem = (t_lgnl*)malloc(sizeof(t_lgnl))))
            return (NULL);
        elem->fd = fd;
        elem->ln = ft_strnew(BUFF_SIZE);
        elem->reste = NULL;
        elem->next = *lst;
        tmp = elem;
        *lst = tmp;
    }
    return (tmp);
}

int ft_search_line(t_lgnl **lst, char *str)
{
    t_lgnl   *tmp;
    size_t   pos_n;
        
    tmp = *lst;
	//printf("tmp->reste avant le search : %s\n", tmp->reste);
    if (ft_strchr(str, '\n') != NULL)
	{
        pos_n = (ft_strchr(str, '\n') - str);
		//printf("pos_n --> %zu", pos_n);
		//printf("Dans le Search_line if tmp->ln : %s tmp->reste : %s\n", tmp->ln, tmp->reste);
        tmp->ln = ft_strsub(str, 0, pos_n);
		//tmp->ln = ft_strjoin(tmp->ln, ft_strsub(str, 0, pos_n));
		tmp->reste = ft_strsub(str, pos_n + 1, ft_strlen(str) - pos_n);
        return (1);
    }
	else
    {
        tmp->ln = ft_strjoin(tmp->ln, str);
		//printf("Dans le Search_line else tmp->ln : %s tmp->reste : %s\n", tmp->ln, tmp->reste);
        if (tmp->reste)
			free(tmp->reste);
        	tmp->reste = NULL;
		//printf("Dans le Search_line else free tmp->ln : %s tmp->reste : %s\n", tmp->ln, tmp->reste);
        return (0);
    }
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static	t_lgnl			*tmpstr;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	
	ret = 0;
	if (fd < 3 || BUFF_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (-1);
	
	tmpstr = ft_lstsearchcreate(&tmpstr, fd);
	//ft_putstr("     Search lancé dans le reste... \n");
	if (tmpstr->reste != NULL)
	{
		if (ft_search_line(&tmpstr, tmpstr->reste) == 1)
		{	
			*line = (tmpstr->ln);
			return (1);
		}
		/*else
		{
			printf("\n Search dans reste  --> Pas de nl!\n");
		}*/
	}
	//ft_putstr("\n     Read lancé... \n");
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret == 0)
			return (0);
		buff[ret] = '\0';
		if (BUFF_SIZE == 1 && buff[0] != '\n')
			ft_search_line(&tmpstr, buff);
		else if (ft_search_line(&tmpstr, buff) == 1)
			{	
				//printf("Dans le Search_line else tmp->ln : %s tmp->reste : %s ret :%d\n", tmpstr->ln, tmpstr->reste, ret);
				*line = (tmpstr->ln);
				return (1);
			}
		if (ret < BUFF_SIZE)
		{	
			*line = (tmpstr->ln);
			return (1);
		}
	}
	return (0);
}