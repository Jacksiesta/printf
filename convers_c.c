/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:13:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/18 17:54:19 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_char_zero(t_flag *flag)
{
	char	*c;

	c = ft_strdup("\0");
	if (flag->width)
	{
		printf("whut :%s\n", c);
		return (ft_strjoin(pad_maker(' ', flag->width - 1), c));
//		return (add_char_to_str(c, pad_maker(' ', flag->width - 1), 1));
	}
	return (0);


}


char	*convers_char(va_list ap, t_flag *flag)
{
	char	*final;
	char	c;

	c = va_arg(ap, int);
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
