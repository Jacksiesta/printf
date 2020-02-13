/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:53:26 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/13 17:07:42 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_hex_zero(t_flag *flag)
{
	char	*final;

	final = ft_strdup("0");
	if (flag->minus)
		if (flag->width > 1)
			final = ft_strjoin(final, pad_maker(' ', flag->width - 1));
	if (flag->zero)
		if (flag->width > 1)
			final = ft_strdup(pad_maker('0', flag->width));
	if (flag->width > 1 && !flag->minus && !flag->zero)
		final = ft_strjoin(pad_maker(' ', flag->width - 1), final);
	return (final);
}

char	*convers_hex_precision(t_flag *flag, int size, char *init)
{
	char	*final;

	if (flag->precision > size)
		final = ft_strjoin(pad_maker('0', flag->precision - size), init);
	else
		final = ft_strdup(init);
	return (final);
}

char	*convers_hex_width(t_flag *flag, char *init, char *fn)
{
	char	*rt;

	if (flag->width && !flag->minus && !flag->zero &&
			flag->width > ft_strlen(init))
	{
		if (flag->precision != -1 && flag->precision > ft_strlen(init))
			rt = ft_strjoin(pad_maker(' ', flag->width - flag->precision), rt);
		else
			rt = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(init)), rt);
	}
	return (rt);
}

char	*convers_hex(va_list ap, t_flag *flag)
{
	char						*fn;
	char						*init;
	long long unsigned int		num;

	num = va_arg(ap, long long unsigned int);
	init = ft_x(num);
	fn = ft_strdup("");
	if (num == 0 && flag->precision < 0)
		return (convers_hex_zero(flag));
//	if (num == 4294967295)
//		return ("ffffffff");
	if (flag->precision)
		fn = convers_hex_precision(flag, ft_strlen(init), init);
	if (flag->minus && flag->width > ft_strlen(init))
		fn = ft_strjoin(fn, pad_maker(' ', flag->width - ft_strlen(fn)));
	if (flag->zero && flag->width > ft_strlen(init))
		fn = ft_strjoin(pad_maker('0', flag->width - ft_strlen(init)), fn);
	if (flag->width && !flag->minus && !flag->zero &&
			flag->width > ft_strlen(init))
	{
		if (flag->precision == 0 && num == 0)
			return (pad_maker(' ', flag->width));
		fn = convers_hex_width(flag, init, fn);
	}
	return (fn);
}
