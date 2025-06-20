/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:58:43 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/01 20:04:05 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printadress(unsigned long int adr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (adr >= 16)
	{
		ft_printadress(adr / 16, len);
		ft_printadress(adr % 16, len);
	}
	else
		*len += write(1, &base[adr], 1);
}

static void	ft_search_arg2(va_list arg, const char *format, int *len)
{
	unsigned long int	tmp;

	if (*format == 'p')
	{
		tmp = va_arg(arg, unsigned long int);
		if (tmp)
		{
			*len += write(1, "0x", 2);
			ft_printadress(tmp, len);
		}
		else
			*len += write(1, "(nil)", 5);
	}
	else if (*format == 'u')
		ft_putnbrunsigned(va_arg(arg, unsigned int), len);
	else
		*len = -1;
}

static void	ft_search_arg(va_list arg, const char *format, int *len)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (*format == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (*format == '%')
		ft_putchar('%', len);
	else if (*format == 'x')
		ft_putnbr_base(va_arg(arg, int), "0123456789abcdef", len);
	else if (*format == 'X')
		ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF", len);
	else
		ft_search_arg2(arg, format, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	while (*format && len != -1)
	{
		if (*format == '%')
		{
			ft_search_arg(arg, format + 1, &len);
			format++;
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(arg);
	return (len);
}
/*
int main()
{
	int 	i;
	void *test;
	void *test2;
	char *str = '\0';
	test = "okok";
	test2 = NULL;
	
	//ft_printf("bla bla %d%d ok %s %c %x %p %p", 13,24, 
	"string", 'z', -12289, test, test2);
	
	//i = printf("bla bla %d%d ok %s %c %x %p %p", 13,24, 
	"string", 'z', -12289, test, test2);
	//write(1, "\n", 1);
	//printf("\nreturn : %d", i);
//	i = printf("%s\n", str);
//	ft_printf("%s\n", str);

//	i = printf("%u ", -3);
//	printf("%d\n", i);
//	ft_printf("%u ", -3);
	//i = printf("blabla %d%d %s %u %s %p", 22, 123, "string", -123, str, test);
	i = printf("%d\n", printf("test%", "toto" )) ;
	printf("\nreturn : %d\n", i);
	//ft_printf("blabla %d%d %s %u %s %p", 22, 123, "string", -123, str, test);
	ft_printf("%d\n", printf("test%", "toto" )) ;
}*/
