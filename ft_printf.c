/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:05:39 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:10:56 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t		x;
	t_f			f;
	va_list		arg;
	t_put		put;

	x = 0;
	va_start(arg, format);
	put.pos = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			struc_init(&f);
			put.len_perc = parser(&f, &format[x], arg);
			if (!f.none)
				parse_spec(&format[x + 1], &f, &put, arg);
			x += put.len_perc + 1 - f.none;
		}
		else
			ft_write(format[x], &put);
		x++;
	}
	va_end(arg);
	return (put.pos);
}
