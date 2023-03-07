/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:22:15 by abelge            #+#    #+#             */
/*   Updated: 2022/03/03 16:22:16 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putstr(char *s);
int		ft_putchar(int a);
int		ft_putnbr(int nb);
char	*ft_convert(unsigned long nb, char *base);
int		ft_srch(va_list vag, char str, int a);
int		ft_printf(const char *s, ...);
int		p_adress(unsigned long long nbr);
int		ft_putnbr_osman(unsigned int nb);

#endif
