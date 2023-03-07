/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agitbelge <agitbelge@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:37:02 by abelge            #+#    #+#             */
/*   Updated: 2022/03/03 01:53:42 by agitbelge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	int	i;

	i = 0;
	i += write(1, &a, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += write(1, &s[x++], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	i;
	int				cnt;

	cnt = 0;
	i = 0;
	if (nb < 0)
	{
		cnt += ft_putchar('-');
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		cnt += ft_putnbr(i / 10);
		cnt += ft_putchar((i % 10) + 48);
	}
	else
		cnt += ft_putchar(i + 48);
	return (cnt);
}
