/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 20:42:04 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 16:55:17 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*nstr;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s2)
		return ((tmp = ft_strdup(s1)) ? tmp : NULL);
	if (!s1)
		return ((tmp = ft_strdup(s2)) ? tmp : NULL);
	if (!(nstr = (char *)malloc(sizeof(*nstr) * ft_strlen((char *)s1)
		+ ft_strlen((char *)s2) + 1)))
		return (NULL);
	while (s1[i])
		nstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		nstr[j++] = s2[i++];
	nstr[j] = '\0';
	return (nstr);
}
