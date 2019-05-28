/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 11:17:12 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 11:22:52 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	dest = NULL;
	if (!s)
		return (NULL);
	if (!(dest = (char*)malloc((len + 1) * sizeof(*dest))))
		return (NULL);
	while (len > 0 && i < (len + (size_t)start))
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
