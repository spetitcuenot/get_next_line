/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:36:01 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 16:42:57 by spetitcu    ###    #+. /#+    ###.fr     */
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

typedef struct		s_lgnl
{
	int				fd;
	char			*ln;
	struct s_lgnl	*next;
}					t_lgnl;

int					get_next_line(const int fd, char **line);

#endif
