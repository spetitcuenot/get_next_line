/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 12:27:11 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 12:27:30 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = (147483648);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
