/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/11 15:50:31 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_flag *flag)
{
	flag->zero = 0; // pour pas avoir de valeur residuelle
	flag->minus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->percent = 0;
}

int	parser(va_list ap, const char *str, t_flag *flag) // activates flags
{
    int		x;

    x = 0;
	init_struct(flag);
	if (ft_isalpha(str[x]) == 0)
	{
        while (str[x] == '0')
        {
            flag->zero = 1;
            x++;
        }
        while (str[x] == '-')
        {
            flag->minus = 1;
            x++;
        }
		while (str[x] == '0')
			x++;
        if (str[x] == '*' || (str[x] >= '1' && str[x] <= '9'))
        {
            if (str[x] == '*')
            {
                flag->width = va_arg(ap, int);
                if (flag->width < 0)
                {
                    flag->minus = 1;
                    flag->width = -flag->width;
                }
            }
            else
                flag->width = ft_atoi(&str[x], &x);
        }
        if (str[x] == '.')
        {
            x++;
            if (str[x] == '*')
                flag->precision = va_arg(ap, int);
            else
                flag->precision = ft_atoi(&str[x], &x);
        }
	}
	if (flag->precision != -1 || flag->minus != 0)
		flag->zero = 0;
	if (str[x] == '%')
		flag->percent = 1;
	return (x);
/*	if (str[x] == '%')
		return (1);
    return (0);*/
}

char	*convers_prc(t_flag *flag)
{
	char	*final;
	int		size;

	final = ft_strdup("%");
	if (flag->minus)
		if (flag->width > 1)
			return (ft_strjoin(final, pad_maker(' ', flag->width - 1)));
	if (flag->zero)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker('0', flag->width - 1), final));
	if (flag->width && !flag->minus && !flag->zero)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker(' ', flag->width - 1), final));
	return (final);
}

char	*convers_char(va_list ap, t_flag *flag)
{
	char	*final;
	char	c;

	c = va_arg(ap, int);
	final = ft_strdup("");
	if (c == 0)
		final = ft_strdup("\0");
	if (flag->minus)
	{
		if (flag->width > 1)
		{
			final = pad_maker(' ', flag->width - 1);
			return (add_char_to_str(c, final, 0));
		}
	}
	if (flag->zero)
	{
		if (flag->width > 1)
		{
			final = pad_maker('0', flag->width - 1);
			return (add_char_to_str(c, final, 1));
		}
	}
	if (flag->width && !flag->zero && !flag->minus)
		final = pad_maker(' ', flag->width - 1);
		return (add_char_to_str(c, final, 1));
}

char	*convers_ptr(va_list ap, t_flag *flag)
{
	char	*final;
	char	*init;
	void	*num;

	num = va_arg(ap, void *);
	final = ft_x((int)num);
	final = ft_strjoin(ft_strdup("0x7fff"), final);
	return (final);
}

int		size_percent(const char *str)
{
    int x;
    int	y;

    x = 0;
    y = 1;
    while (str[x] != '%')
        x++;
    while (ft_isalpha(str[x]) == 0)
    {
        x++;
        y++;
    }
    return (y);
}

int		size_percent_percent(const char *str)
{
	int x;

	x = 0;
	while (str[x] != '%')
		x++;
	return (x);
}

int		ft_printf(const char *coucou, ...)
{
	int		x;
	int		y;
	int		z;
	int     len;
	va_list	ap;
	char	*buffer;
	char	*temp;
	t_flag	flag;

	x = 0;
	y = 0;
	z = 0;
	va_start(ap, coucou);
	if (!(buffer = (char *)malloc(sizeof(char) * 1000000)))
		return (0);
	if (!(temp = (char *)malloc(sizeof(char) * 10000000)))
		return (0);
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			temp = ft_strdup("");
			init_struct(&flag);
			z = parser(ap, &coucou[x + 1], &flag);
			temp = ft_strdup(temp_maker(&coucou[x + 1], &flag, ap, z));
			buffer = ft_strjoin(buffer, temp);
			x = x + z;
			y = y + ft_strlen(temp);
		}
		else
			buffer[y] = coucou[x];
		x++;
		y++;
	}
	ft_putstr(buffer);
	return (ft_strlen(buffer));
}

/*
int main()
{
	char c;

	c = 'a';
//	printf("%d\n", ft_printf("YES%7d", 33));
//	printf("%5\n");
//	ft_printf("oui :%5: oui");
//	printf("%p\n", &c);
//	ft_printf("%12%");
	printf("%%");
//	printf("[%d] [%d]", 12345, 56789);
	return (0);
}
*/
