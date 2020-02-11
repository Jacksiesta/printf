/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:01:24 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/11 16:27:17 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_d(va_list ap, t_flag *flag)
{
	char	*init;
	int		num;
	int		size;
	int		neg;
	char	*fin;

	num = va_arg(ap, int);
	neg = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	init = ft_d(num);
	size = ft_strlen(init);
	fin = ft_strdup("");
	if (flag->precision)
	{
		if (flag->precision > size)
			fin = ft_strjoin(pad_maker('0', flag->precision - size), init);
		else
			fin = ft_strdup(init);
	}
	if (flag->minus)
		if (flag->width > size)
			fin = ft_strjoin(fin, pad_maker(' ', flag->width - ft_strlen(fin) - neg));
	if (flag->zero)
		if (flag->width > size)
			fin = ft_strjoin(pad_maker('0', flag->width - size - neg), fin);
	if (flag->width && !flag->minus && !flag->zero)
		if (flag->width > size)
		{
			if (flag->precision == 0 && num == 0)
				return (pad_maker(' ', flag->width));
			if (neg)
				fin = ft_strjoin(ft_strdup(pad_maker('-', 1)), fin);
			if (flag->precision != -1 && flag->precision > size)
				fin = ft_strjoin(pad_maker(' ', flag->width - neg - flag->precision), fin);
			else
				fin = ft_strjoin(pad_maker(' ', flag->width - size - neg), fin);
		}
	if (neg && search_for('-', fin))
		fin = ft_strjoin(ft_strdup(pad_maker('-', 1)), fin);
	return (fin);
}
