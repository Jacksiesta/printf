/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/02 19:20:29 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_flag *flag)
{
	flag->zero_flag = 0; // pour pas avoir de valeur residuelle
	flag->minus_flag = 0;
	flag->width = 0;
	flag->precision = -1;
}

char	*parser(va_list ap, const char *str, t_flag *flag) // activates flags
{
    int		x;

    x = 0;
	init_struct(flag);
	if (ft_isalpha(str[x]) == 0)
	{
        if (str[x] == '0')
        {
            flag->zero_flag = 1;
            x++;
        }
        if (str[x] == '-')
        {
            flag->minus_flag = 1;
            x++;
        }
        if (str[x] == '*' || (str[x] >= '0' && str[x] <= '9'))
        {
            if (str[x] == '*')
            {
                flag->width = va_arg(ap, int);
                if (flag->width < 0)
                {
                    flag->minus_flag = 1;
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
	if (flag->precision != -1 || flag->minus_flag != 0)
		flag->zero_flag = 0;
    return (0);
}

char	*convers_d(va_list ap, t_flag *flag)
{
	char	*init;
	int 	num;
	int		size;
	int		neg;
	char	*final;

	num = va_arg(ap, int);
	neg = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	init = ft_d(num);
	size = ft_strlen(init);
	final = ft_strdup("");
	if (flag->precision)
	{
		if (flag->precision > size)
			final = ft_strjoin(pad_maker('0', flag->precision - size), init);
		else
			final = ft_strdup(init); // gets rid of 0
	}
	if (flag->minus_flag)
	{
		if (flag->width > size)
			final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final) - neg));
	}
	if (flag->zero_flag)
	{
		if (flag->width > size)
			final = ft_strjoin(pad_maker('0', flag->width - size - neg), final);
	}
	if (flag->width && !flag->minus_flag && !flag->zero_flag)
	{
		if (flag->width > size)
		{
			if (flag->precision == 0 && num == 0)
				return (pad_maker(' ', flag->width));
			if (neg)
				final = ft_strjoin(ft_strdup(pad_maker('-', 1)), final);
			if (flag->precision != -1 && flag->precision > size)
				final = ft_strjoin(pad_maker(' ', flag->width - neg - flag->precision), final);	
			else
				final = ft_strjoin(pad_maker(' ', flag->width - size - neg), final);
		}
	}
	if (neg && search_for('-', final))
		final = ft_strjoin(ft_strdup(pad_maker('-', 1)), final);
	return (final);
}

char	*convers_s(va_list ap, t_flag *flag)
{
	char	*init;
	char	*final;
	int		size;
	
	final = ft_strdup("");
	init = va_arg(ap, char *);
	size = ft_strlen(init);
	if (flag->precision != -1)
	{
		if (flag->precision < size)
			final = ft_strdup(cropped_str(init, flag->precision));
		else
			final = ft_strdup(init);
	}
	if (flag->precision == -1)
		final = ft_strdup(init);	
	if (flag->minus_flag)
		if (flag->width > size)
			final = ft_strjoin(final, pad_maker(' ', flag->width - size));
	if (flag->width && !flag->minus_flag)
	{
		if (flag->width > ft_strlen(final))
			final = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(final)), final);	
	}
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

int		ft_printf(const char *coucou, ...)
{
	int		x;
	int		y;
	int     len;
	va_list	ap;
	char	*buffer;
	char	*temp;
	t_flag	flag;

	x = 0;
	y = 0;
	va_start(ap, coucou);
	if (!(buffer = (char *)malloc(sizeof(char) * 10000000000)))
		return (0);
	if (!(temp = (char *)malloc(sizeof(char) * 100000000000)))
		return (0);
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			parser(ap, &coucou[x + 1], &flag);
		    len = size_percent(coucou);
			if (coucou[x + len - 1] == 's')
				temp = convers_s(ap, &flag);
			else if (coucou[x + len - 1] == 'c')
				ft_c(ap);
			else if (coucou[x + len - 1] == 'd' || coucou[x + len - 1] == 'i')
				temp = convers_d(ap, &flag);
			else if (coucou[x + len - 1] == 'x')
				ft_x(ap);
			else if (coucou[x + len - 1] == 'X')
				ft_xx(ap);
			else if (coucou[x + len - 1] == 'u')
				ft_u(ap);
			else if (coucou[x + len - 1] == 'p')
				ft_p(ap);
//			if (coucou[x + len - 1] == '%')
			buffer = ft_strjoin(buffer, temp);
			x = x + len - 1;
			y = y + ft_strlen(temp) - 1;
		}
		else
			buffer[y] = coucou[x];
		x++;
		y++;
	}
	ft_putstr(buffer);
	return (ft_strlen(buffer));
}

//int main()
//{
////	printf("%d\n", ft_printf("YES%7d", 33));
//	ft_printf("%5.2s\n", "abc");
//	printf("%5.2s\n", "acb");
////	printf("[%d] [%d]", 12345, 56789);
//	return (0);
//}
