/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:48:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/04 16:25:53 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_c(t_f *f, t_put *put)
{
	init_put(put);
	if (f->width > 1)
		put->width = f->width - 1;
}

static void		convers_c_percent(t_f *f, t_put *put, char c)
{
	if (f->zero && !f->minus)
	{
		while (put->width > 0)
		{
			ft_write('0', put);
			put->width--;
		}
		ft_write(c, put);
	}
}

void			convers_c(va_list arg, t_f *f, t_put *put, int i)
{
	char c;

	fill_put_c(f, put);
	if (i)
		c = '%';
	if (i && f->zero && !f->minus)
	{
		convers_c_percent(f, put, c);
		return ;
	}
	if (!i)
		c = va_arg(arg, int);
	if (f->minus)
	{
		ft_write(c, put);
		while (put->width--)
			ft_write(' ', put);
	}
	else if (!f->minus)
	{
		while (put->width--)
			ft_write(' ', put);
		ft_write(c, put);
	}
}
