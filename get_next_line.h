/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:36:01 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 17:05:17 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

// buffer a 1 non ok
// buffer a 2 non ok
// buffer a 3 non ok
// buffer a 4 affichage de 3 char au lieu de 8 par line !
// buffer a 5 non ok
// buffer a 6 non ok
// buffer a 7 non ok
// si pas de \n dans fichier non ok
// buffer a 9 non ok


typedef struct		s_lgnl
{
	int				fd;
	char			*reste;
	char			*ln;
	struct s_lgnl	*next;
}					t_lgnl;

int					get_next_line(const int fd, char **line);
//int					ft_search_line(t_lgnl **lst, char *str);
//t_lgnl				*ft_lstsearchcreate(t_lgnl **lst, int fd);

#endif
