/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agitbelge <agitbelge@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:59:07 by abelge            #+#    #+#             */
/*   Updated: 2022/03/03 01:52:14 by agitbelge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(unsigned long nb, char *base)
{
	static char	str[50];
	char		*s;

	s = &str[49];
	*s = 0;
	*(--s) = base[nb % 16];
	nb /= 16;
	while (nb != 0)
	{
		*(--s) = base[nb % 16];
		nb /= 16;
	}
	return (s);
}

int	p_adress(unsigned long long nbr)
{
	int	syc;

	syc = 0;
	if (nbr == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	syc += ft_putstr("0x");
	syc += ft_putstr(ft_convert(nbr, "0123456789abcedf"));
	return (syc);
}

int	ft_putnbr_osman(unsigned int n)
{
	int				cnt;
	unsigned int	i;
	char			str[10];

	cnt = 0;
	i = 0;
	if (n == 0)
		cnt += ft_putchar('0');
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		cnt += ft_putchar(str[i]);
	return (cnt);
}
