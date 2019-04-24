/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maingnl.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 16:03:59 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 16:36:01 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

/*

int main(void)
{
	int fd;
	int ret;
	char *str;
	//(void)argc;
	
	str = NULL;
	ret = 2;
	fd = open("tstgnl", O_RDONLY);
	printf("ouverture  : %d\n", fd);
	if (fd == -1)
	{	
		ft_putstr("open() failed");
		return (-1);
	}
	printf("fd suite open dans le main : %d\n", fd);
	
		get_next_line(fd, &str);
		printf("\ncode retour de gnl depuis le while main : %d\n", ret);
		printf("\nCode retour final de gnl depuis le main : %d\n", ret);
		close(fd);

	fd = open("tstgnl2", O_RDONLY);
	printf("ouverture  : %d\n", fd);
	if (fd == -1)
	{	
		ft_putstr("open() failed");
		return (-1);
	}
	printf("fd suite open dans le main : %d\n", fd);
	while ((ret = get_next_line(fd, &str)) && (ret >= 0))
	{
		get_next_line(fd, &str);
		printf("\ncode retour de gnl depuis le while main : %d\n", ret);
	}
		printf("\nCode retour final de gnl depuis le main : %d\n", ret);
close(fd);
	fd = open("tstgnl3", O_RDONLY);
	printf("ouverture  : %d\n", fd);
	if (fd == -1)
	{	
		ft_putstr("open() failed");
		return (-1);
	}
	printf("fd suite open dans le main : %d\n", fd);
	while ((ret = get_next_line(fd, &str)) && (ret >= 0))
	{
		get_next_line(fd, &str);
		printf("\ncode retour de gnl depuis le while main : %d\n", ret);
	}
		printf("\nCode retour final de gnl depuis le main : %d\n", ret);


	//free(str);
	str = NULL;
	close(fd);
	return (0);
}
*/
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;
	/*int		fd1;	
	int		fd2;	
	int		fd3;	
	int		ret1;	
	int		ret2;	
*/
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("\n\033[31;01mCode retour gnl : \033[00m%d\033[00m \033[34;01m  --> la line : \033[32;01m%s\033[00m\n", ret, line);
		/*if (line)
			free(line);*/
	}
	printf("\033[31;01m en fin de while retour sortie GNL : \033[00m%d\n", ret);
	if (line)
		free(line);
		
	//printf("\n\033[33;01m ------------------------------------------------------------------------------------ \033[00m\n\n");
/*
	fd1 = open(av[2], O_RDONLY);
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("\n\033[31;01m Code retour gnl  fd1 : \033[00m%d\033[00m \033[34;01m---> la line \033[00m %s\n", ret, line);
		if (line)
			free(line);
	}
	printf("\n\033[31;01m en fin de while retour sortie GNL : \033[00m%d\n", ret);
	if (line)
		free(line);

	printf("\n\033[33;01m ------------------------------------------------------------------------------------ \033[00m\n\n");

	fd2 = open(av[3], O_RDONLY);
	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("\n\033[31;01m Code retour gnl  fd2 : \033[00m%d\033[00m \033[34;01m---> la line \033[00m %s\n", ret, line);
		if (line)
			free(line);
	}
printf("\n\033[31;01m en fin de while retour sortie GNL : \033[00m%d\n", ret);	if (line)
		free(line);

	printf("\n\033[33;01m ------------------------------------------------------------------------------------ \033[00m\n\n");

	fd3 = open(av[4], O_RDONLY);
	ret1 = 1;
	ret2 = 1;
	while (ret2 > 0)
	{
		ret1 = get_next_line(fd, &line);
		printf("\n\033[31;01m Code retour gnl  fd : %d\033[00m \033[34;01m---> la line \033[00m %s\n", ret1, line);
		if (line)
			free(line);
		ret2 = get_next_line(fd3, &line);
		printf("\n\033[31;01m Code retour gnl  fd3 : \033[00m%d\033[00m \033[34;01m---> la line \033[00m %s\n", ret2, line);
		if (line)
			free(line);
	}
	printf("\n\033[31;01m en fin de while retour sortie GNL : \033[00m%d\n", ret1); */
	
	if (close(fd) == 0)
		return 	(printf("\n\033[33;01m Close fd ok -------------------- \033[00m\n\n"));
	else 
		return 	(printf("\n\033[33;01m Close error -------------------- \033[00m\n\n"));
	/*close(fd1);	
	close(fd2);	
	close(fd3);	*/
	
	return (0);
}