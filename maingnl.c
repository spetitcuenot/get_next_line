/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maingnl.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 16:03:59 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 17:27:06 by spetitcu    ###    #+. /#+    ###.fr     */
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
