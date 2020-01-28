/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/28 15:58:54 by jherrald         ###   ########.fr       */
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
	while (str[x])
	{
        if (str[x] == '-')
        {
            flag->minus_flag = 1;
            x++;
        }
        if (str[x] == '0')
        {
            flag->zero_flag = 1;
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
			{
                flag->width = ft_atoi(&str[x], &x);
				x = x + ft_lenght_int(flag->width);
			}
        }
        if (str[x] == '.')
        {
            x++;
            if (str[x] == '*')
                flag->precision = va_arg(ap, int);
            else
                flag->precision = ft_atoi(&str[x], &x);
			break;
        }
		x++;
	}
	if (flag->precision != -1 || flag->minus_flag != 0)
		flag->zero_flag = 0;
    return (0);
}

char    *convers_d(va_list ap, t_flag *flag)
{
	char		*init;
	int			num;
	int			size;
	int			neg;
	char		*pad;
	char		*final;

	num = va_arg(ap, int);
	neg = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	init = ft_d(num); // number stocked in string
	size = ft_strlen(init);
	printf("size is %d\n", size);
	printf("init string is %s\n", init);
	printf(":%d precision t1\n", flag->precision);
	printf(":%d width t1 \n", flag->width);
	printf(":%d zero flag t1 \n", flag->zero_flag);
	printf(":%d minus flag t1 \n", flag->minus_flag);
	printf("init is %s\n____\n", init);
	if (neg)
		final = ft_strdup(pad_maker('-', 1));
//	while (flag->width && flag->width > flag->precision && flag->width > size)
//	{
//		write(1, " ", 1);
//		flag->width--;
//	}
	printf("final t1 %s\n", final);
	if (flag->precision && flag->precision > size)
	{
		final = ft_strjoin(final, pad_maker('0', flag->precision - size));
		printf("final t2 %s\n", final);
	}
	final = ft_strjoin(final, init);
	printf("final t3 %s\n", final);
	if (flag->width && flag->width > flag->precision)
	{
		final = ft_strjoin(pad_maker(' ', flag->width - flag->precision - 1), final);
		printf("final t4 %s\n", final);

	}
	ft_putstr(final);
	return (NULL);
}

int		size_percent(const char *str) // len de % à specifier
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
	int     len;
	va_list	ap;
	t_flag	flag;

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			parser(ap, &coucou[x + 1], &flag); // fill in flags
		    len = size_percent(coucou);
			if (coucou[x + len - 1] == 's')
				ft_s(ap);
			if (coucou[x + len - 1] == 'c')
				ft_c(ap);
			if (coucou[x + len - 1] == 'd' || coucou[x + len - 1] == 'i')
				convers_d(ap, &flag);
			if (coucou[x + len - 1] == 'x')
				ft_x(ap);
			if (coucou[x + len - 1] == 'X')
				ft_xx(ap);
			if (coucou[x + len - 1] == 'u')
				ft_u(ap);
			if (coucou[x + len - 1] == 'p')
				ft_p(ap);
			x = x + len;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{
	int		numba = -45;

//	ft_printf("%*d\nouioui \n", -10, numba);
	ft_printf("%7.5d p numba\n", numba);
	printf("%7.5d p Actual printf\n", numba);
	printf("%7.5d n Actual printf\n", -numba);
//	printf("%-*d\n", 45, 1234);
//	printf("%*d\n", -45, 1234);
//	printf("%-45d\n", 1234);
//	i = printf("OG test : %x \n", numba);
//	printf("%d i == %d\n", numba, i);
	//	return (0);
}
