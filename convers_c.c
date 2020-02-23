/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:13:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/23 15:55:35 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*add_zero_to_str(char *str, int i, int len)
{
	char 	*final;
	int		x;

	x = 0;
	if (!(final = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	if (i == 1)
	{
		final[0] = '\0';
	}
	while (len)
	{
		final[x + i] = str[x];
		x++;
		len--;
	}
	if (i == 0)
	{
		final[x + i] = '\0';
		x++;
	}
	final[x + i] = '\0';
//	printf("finnnal is%s\n", final);
	return (final);
}

char	*convers_char_zero(t_flag *flag)
{
	char	*c;
	char	*final;
	int		x;
	int		len;

	x = 0;
	len = flag->width;
	if (!(c = malloc(sizeof(char) * 20)))
		return (0);
//	c[0] = '\0'; //c[x] = c[x + 1]
//	c[1] = '\0';
	if (flag->precision > -1)
	{
		return (c);
	}
	if (flag->width)
	{
		//printf("c is worth==%s\n", c);
		return (c);
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
	{
		//printf("c is :%c\n", c);
		return (convers_char_zero(flag));
	}
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
