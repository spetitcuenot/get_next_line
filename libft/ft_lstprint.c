/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 15:03:33 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 14:45:17 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
}
