/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:51:21 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:51:42 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flag(t_f *f, t_put *put, int nb)
{
	if (f->zero)
	{
		if (put->neg)
			ft_write('-', put);
		while (put->width--)
			ft_write('0', put);
		ft_write_num(nb, put);
	}
	if (f->minus)
	{
		if (put->neg)
			ft_write('-', put);
		if (f->precision > 0)
			while (put->precision--)
				ft_write('0', put);
		ft_write_num(nb, put);
		while (put->width--)
			ft_write(' ', put);
	}
}

static void	apply_width(t_put *put, int nb)
{
	while (put->width--)
		ft_write(' ', put);
	if (put->neg)
		ft_write('-', put);
	while (put->precision--)
		ft_write('0', put);
	ft_write_num(nb, put);
}

static void	apply_precision(t_put *put, int nb)
{
	if (put->neg)
		ft_write('-', put);
	while (put->precision--)
		ft_write('0', put);
	ft_write_num(nb, put);
}

static void	apply_precision_param_zero(t_f *f, t_put *put, int nb)
{
	if (f->precision == 0 && nb == 0)
	{
		put->width = f->width;
		while (put->width--)
			ft_write(' ', put);
	}
	if (!put->precision && !put->width)
	{
		if (put->neg)
			ft_write('-', put);
		ft_write_num(nb, put);
	}
}

void		convers_d(va_list arg, t_f *f, t_put *put)
{
	int		nb;

	nb = va_arg(arg, int);
	put->len = ft_strlen_int(nb);
	init_put(put);
	if (nb < 0)
	{
		nb = -nb;
		put->neg = 1;
	}
	fill_put(f, put);
	if ((f->precision == 0 && nb == 0) || (!put->precision && !put->width))
	{
		apply_precision_param_zero(f, put, nb);
		return ;
	}
	else if (nb == 0 && !f->width && f->precision == -1)
		ft_write('0', put);
	if (f->zero || f->minus)
		apply_flag(f, put, nb);
	else if (!f->minus && !f->zero && put->width)
		apply_width(put, nb);
	if (put->precision && !put->width && !f->zero && !f->minus)
		apply_precision(put, nb);
}
