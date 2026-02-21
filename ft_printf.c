/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:17:25 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/21 10:56:23 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_ptr(unsigned long ptr, t_lst *a)
{
	if (ptr == 0)
		for_str("(nil)", a, 0);
	else
	{
		for_char('0', a);
		for_char('x', a);
		for_hexa(ptr, 'x', a);
	}
}

void	for_unsigned(unsigned int n, t_lst *a)
{
	if (n >= 10)
		for_unsigned(n / 10, a);
	write(1, &"0123456789"[n % 10], 1);
	a->num++;
}

void	for_hexa(unsigned long i, char c, t_lst *a)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (i == 0)
	{
		for_char('0', a);
		return ;
	}
	if (i < 16)
		for_char(hex[i], a);
	else
	{
		for_hexa(i / 16, c, a);
		for_hexa(i % 16, c, a);
	}
}

void	print(char c, va_list ap, t_lst *a)
{
	if (c == 's')
		for_str(va_arg(ap, char *), a, 0);
	else if (c == 'd' || c == 'i')
		for_nbr(va_arg(ap, int), a);
	else if (c == 'p')
		for_ptr(va_arg(ap, unsigned long), a);
	else if (c == 'c')
		for_char(va_arg(ap, int), a);
	else if (c == 'u')
		for_unsigned(va_arg(ap, unsigned int), a);
	else if (c == 'x' || c == 'X')
		for_hexa(va_arg(ap, unsigned int), c, a);
	else if (c == '%')
		for_char('%', a);
	else
	{
		write(1, &c, 1);
		a->num++;
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_lst	*a;
	int		b;

	a = malloc(sizeof(t_lst));
	a->num = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			print(*(++format), ap, a);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			a->num++;
		}
	}
	va_end(ap);
	b = a->num;
	free(a);
	return (b);
}
