/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:17:25 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/20 18:18:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arlen(int n)
{
	long	a;
	int		i;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	inarr(char *back, int a, int backlen)
{
	long	n;

	n = a;
	if (n < 0)
	{
		back[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		inarr(back, n / 10, backlen - 1);
		inarr(back, n % 10, backlen);
	}
	if (n < 10)
		back[backlen] = n + 48;
}

char	*ft_itoa(int n)
{
	int		backlen;
	char	*back;

	backlen = arlen(n);
	back = malloc((sizeof(char) * backlen) + 1);
	if (!back)
		return (0);
	inarr(back, n, backlen - 1);
	back[backlen] = '\0';
	return (back);
}

void for_str(char *str, t_lst *a, int i)
{
	if (!str)
	{
		for_str("(null)", a, 0);
		return ;
	}
	while (str[i] != '\0')
	{
		write(1, &str[i++], 1);
		a->num++;
	}
}

void	for_char(int c, t_lst *a)
{
	write(1, &c, 1);
	a->num++;
}

void for_nbr(int i, t_lst *a)
{
    if (i == -2147483648)
	{
		for_nbr((i / 10), a);
		for_char('8', a);
	}
	else if (i < 0)
	{
		for_char('-', a);
        i *= -1;
		for_nbr(i ,a);
	}
	else
	{
		if (i >= 10)
			for_nbr((i / 10), a);
		for_char(((i % 10) + 48), a);
	}
}

void for_ptr(unsigned long ptr, t_lst *a)
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

void for_int(int i, t_lst *a)
{
    char	*num;

	if (i == 0)
	{
		write(1, "0", 1);
        a->num++;
    }
	else
	{
		num = ft_itoa(i);
		for_str(num, a, 0);
		free(num);
	}
}

void for_hexa(unsigned long i, char c, t_lst *a)
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

void print(char c, va_list ap, t_lst *a)
{
    if(c == 's')
        for_str(va_arg(ap, char *), a, 0);
    else if(c == 'd' || c == 'i')
        for_nbr(va_arg(ap, int), a);
    else if(c == 'p')
        for_ptr(va_arg(ap, unsigned long), a);
    else if(c == 'c')
        for_char(va_arg(ap, int), a);
    else if(c == 'u')
        for_int(va_arg(ap, unsigned int), a);
    else if(c == 'x' || c == 'X')   
        for_hexa(va_arg(ap, unsigned int), c, a);
    else if(c == '%')
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
    t_lst  *a;
    
    a = malloc(sizeof(t_lst));
    a->num = 0;
	va_start(ap, format);
    while(*format)
    {
        if(*format == '%')
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
    return(a->num);
}
