/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maingnl.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 16:03:59 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 16:13:59 by spetitcu    ###    #+. /#+    ###.fr     */
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

int	get_next_line(const int fd, char **line);
/*{
	//(void)line;
	t_list	*lst;
	int		i;
	t_list 	*elem;
	char	*str;
	static char *line;
	unsigned char	buff[BUFF_SIZE];
	
	i = 0;
	ft_putstr("avant read\n");
	while ((read(fd, &buff, BUFF_SIZE + 1) > 0))
	{
		elem = ft_lstnew(buff, BUFF_SIZE + 1);
		ft_lstaddend(&lst, elem);
	}
	ft_lstprint(lst);
	
	while (lst)
	{
		str = lst->content;
		while (str[i])
			if (str[i] == "\n")
			line[i] = str;
		

		lst = lst->next;
		i++;
	}
	line[i] = '\0';
	return (0);
}
*/

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;
	(void)argc;
	
	str = NULL;
	ret = 2;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{	
		ft_putstr("open() failed");
		return (-1);
	}
	printf("fd suite open dans le main : %d\n", fd);
	ret = get_next_line(fd, &str);
	   printf("\ncode retour de gnl : %d\n", ret);
	free(str);
	str = NULL;
	close(fd);
	return (0);
}
