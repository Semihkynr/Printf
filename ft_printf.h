/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:17:41 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/21 10:51:36 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	size_t	num;
}			t_lst;

void		for_str(char *str, t_lst *a, int i);
void		for_char(int c, t_lst *a);
void		for_nbr(int i, t_lst *a);
void		for_ptr(unsigned long ptr, t_lst *a);
void		for_unsigned(unsigned int i, t_lst *a);
void		for_hexa(unsigned long i, char c, t_lst *a);

#endif