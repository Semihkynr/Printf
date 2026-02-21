/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:26:38 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/21 10:30:44 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_str(char *str, t_lst *a, int i)
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

void	for_nbr(int i, t_lst *a)
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
		for_nbr(i, a);
	}
	else
	{
		if (i >= 10)
			for_nbr((i / 10), a);
		for_char(((i % 10) + 48), a);
	}
}
