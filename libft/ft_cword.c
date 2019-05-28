/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cword.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 14:44:03 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 14:44:20 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_cword(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (((s[i - 1] == c) && (s[i] != c)) || ((s[i] != c) && (i == 0)))
			count++;
		i++;
	}
	return (count);
}
