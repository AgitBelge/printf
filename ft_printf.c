/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:40:52 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 07:01:08 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_osman(va_list list, char str, int a)
{
	if (str == '%')
		a = write(1, "%", 1);
	else if (str == 'c')
		a = ft_putchar(va_arg(list, int));
	else if (str == 's')
		a = ft_putstr(va_arg(list, char *));
	else if (str == 'd')
		a = ft_putnbr(va_arg(list, int));
	else if (str == 'i')
		a = ft_putnbr(va_arg(list, int));
	else if (str == 'p')
		a = p_adress(va_arg(list, unsigned long long));
	else if (str == 'u')
		a = ft_putnbr_osman(va_arg(list, unsigned int));
	else if (str == 'x')
		a = ft_putstr(ft_convert(va_arg(list, unsigned int), \
		"0123456789abcdef"));
	else if (str == 'X')
		a = ft_putstr(ft_convert(va_arg(list, unsigned int), \
		"0123456789ABCDEF"));
	else
		str++;
	return (a);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			a;
	va_list		list;

	a = 0;
	va_start(list, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			a += ft_osman(list, s[++i], a);
		else
			a += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (a);
}

//int	main(void)
//{

//	int x;
//	int y;

//	x = 0;
//	y = 0;	
//	x = ft_printf("cakmaaa: %%\n");
//	printf("cakmaaa toplam sayı: %d\n", x);
//	y = printf("original: %%\n");
//	printf("original toplam sayi: %d\n", y);	
//}
//int main()
//{
//	char b[] = "a";
//	int i;
//	int x;
//	i = ft_printf("ft_printf  value: %p\n", b);
//	x = printf("org_printf value: %p\n", b);
//	printf("total: %d\n", i);
//	printf("total: %d\n", x);
//	return (0);
//}
//int main()
//{
//	int x;
//	int y;

//	x =0;
//	y =0;
//	x = ft_printf("%%%c\n", 'c');
//	y = printf("%%%c\n", 'c');
//	ft_printf("%%%d\n", x);
//	printf("%%%d\n", y);
//}
//int main()
//{
//	int i;
//	int a;

//	i = 0;
//	a = 0;
//	i = ft_printf("%%%s", "selam");
//	a = printf("%%%s", "selam");
//	ft_printf("%%%d", i);
//	printf("%%%d");
//}
