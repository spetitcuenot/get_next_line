/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 14:39:51 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 15:05:23 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	get_next_line(const int fd, char **line)
{
	//(void)line;
	t_list			*lst;
	t_list			*tmp;
	t_list			*elem;
	
	unsigned char	buff[BUFF_SIZE];
	char			*strd;
	static char		*strstat;
	int				i;
	int				j;

	i = 0;
	j = 0;
	lst = NULL;
	tmp = NULL;
	strd = ft_strnew(1);
	if (fd < 0 || *line != NULL || BUFF_SIZE == 0)
		return (-1);
	ft_putstr("read lancé... (dans GNL)\n");
	while (read(fd, &buff, BUFF_SIZE) > 0)
	{
		elem = ft_lstnew(buff, BUFF_SIZE + 1);
		ft_lstaddend(&tmp, elem);
		printf("tmp->content : %s\n", tmp->content);
		if (ft_strchr(tmp->content, '\n') != NULL)
		{
			if (j != 0)
			{
				*line = ft_strjoin(strd, ft_strsub(tmp->content, 0, (ft_strlen_c(tmp->content, '\n'))));
				strstat = ft_strsub(tmp->content, ft_strlen_c(tmp->content, '\n'), (BUFF_SIZE - ft_strlen_c(tmp->content, '\n')));
				ft_putstr("\naffichage ligne 1 :\n");
			}
			else
			{ 
				*line = ft_strsub(tmp->content, 0, (ft_strlen_c(tmp->content, '\n')));
				strstat = ft_strsub(tmp->content, ft_strlen_c(tmp->content, '\n'), (BUFF_SIZE - ft_strlen_c(tmp->content, '\n')));
			}
			ft_putstr("\naffichage ligne 2 :\n");
			ft_putstr(*line);
			return (1);
		}
		else
		{
			strd = ft_strjoin(strd, tmp->content);
			printf("strd join :%s\n longeur de strd :%zu \n\n", strd, ft_strlen(strd));
			j++;
		}
		tmp = tmp->next;
	}
	ft_putstr("affichage liste chainée en totalité...\n");
	ft_lstprint(tmp);
	ft_putstr("\nfin affichage liste chainée\n");
	
	return (0);
}
