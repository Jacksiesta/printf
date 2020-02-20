/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:13:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/20 18:20:25 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_char_zero(t_flag *flag)
{
	char	*c;

	if (!(c = malloc(sizeof(char) * 1)))
		return (0);
	c[0] = '\0';
	write(1, &c[0], 1);
	if (flag->precision > -1)
	{
		return (c);
	}
	if (flag->width)
	{
		return (ft_strjoin(pad_maker(' ', flag->width - 1), c));
	}
	return (c);
}


char	*convers_char(va_list ap, t_flag *flag)
{
	char	*final;
	char	c;

	c = (char)va_arg(ap, int);
//	printf("c is %c\n", c);
	final = ft_strdup("");
	if (c == 0)
		return (convers_char_zero(flag));
	//	final = ft_strdup("\0");
	if (flag->minus)
		if (flag->width > 1)
		{
			final = pad_maker(' ', flag->width - 1);
			return (add_char_to_str(c, final, 0));
		}
	if (flag->zero)
		if (flag->width > 1)
		{
			final = pad_maker('0', flag->width - 1);
			return (add_char_to_str(c, final, 1));
		}
	if (flag->width && !flag->zero && !flag->minus)
		final = pad_maker(' ', flag->width - 1);
	return (add_char_to_str(c, final, 1));
}
