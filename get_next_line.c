/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 18:15:20 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 16:08:36 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		gnlerror(int fd, char **line)
{
	char	*buff;
	int		i;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)) || read(fd, buff, 0) == -1)
		i = 1;
	ft_strdel(&buff);
	return (i ? -1 : 0);
}

static t_lgnl	*ft_lstsearchcreate(int fd, t_lgnl **list)
{
	t_lgnl *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_lgnl *)malloc(sizeof(t_lgnl))))
		return (NULL);
	tmp->fd = fd;
	tmp->ln = NULL;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static char		*ft_read(int fd, char *str)
{
	char	*tmp;
	char	*buff;
	int		ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (NULL);
	ret = 1;
	while (ret && (!(ft_strchr(str, '\n'))))
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&tmp);
	}
	if (!ret && ft_strlen(str) > 0)
	{
		tmp = str;
		if (!(str = ft_strjoin(str, "\n")))
			return (NULL);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (str);
}

static char		*search_line(char **str)
{
	char *line;
	char *pos_n;
	char *tmp;

	pos_n = ft_strchr(*str, '\n');
	if (pos_n)
	{
		if (!(line = ft_strsub(*str, 0, pos_n - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(pos_n + 1)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else if (!(line = ft_strdup(*str)))
		return (NULL);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_lgnl	*tmpstr;
	t_lgnl			*tmp;

	if (!(tmp = ft_lstsearchcreate(fd, &tmpstr)) || gnlerror(fd, line))
		return (-1);
	if (!ft_strlen((tmp->ln = ft_read(fd, tmp->ln))))
	{
		ft_memdel((void **)&tmp->ln);
		return (0);
	}
	return ((*line = search_line(&tmp->ln)) ? 1 : -1);
}
