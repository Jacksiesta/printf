/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/27 14:10:42 by jherrald         ###   ########.fr       */
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
    int x;

    x = 1;
	init_struct(flag);
    if (str[x] == '-')
    {
        flag->minus_flag = 1;
        x++;
    }
	if (str[x] == '0')
    {
        flag->zero_flag = 1;
        x++;
		printf("%d flag zero t0 \n", flag->zero_flag);
    }
    if (str[x] == '*' || (str[x] >= '0' && str[x] <= '9'))
    {
        if (str[x] == '*')
            flag->width = va_arg(ap, int);
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
	if (flag->precision != -1 || flag->minus_flag != 0)
		flag->zero_flag = 0;
	
	printf("%d flag zero t2 \n", flag->zero_flag);
    return (0);
}

char    *convers_d(va_list ap, t_flag *flag)
{
	char		*init;
	char		*final;
	int			num;
	int			size;
	int			num_zero;

	num = va_arg(ap, int);
	init = ft_d(num); // number stocked in string
	size = ft_strlen(init);
	final = "wouwou";
	printf("%d precision t1\n", flag->precision);
	printf("%d width t1 \n", flag->width);
	printf("%d zero flag t1 \n", flag->zero_flag);
	printf("%d minus flag t1 \n", flag->minus_flag);
	if (init[0] == '-')
	{
		*final = '-';
		size--; // precision doesn't take into account neg
		final++; // go to next character
	}
	if (flag->precision && flag->precision > size - 1)
	{
		num_zero = flag->precision - size;
	}
	ft_putstr(init);
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
			parser(ap, &coucou[x], &flag); // fill in flags
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
			x = x + len;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{

	int		numba = 45;
	ft_printf("testING :::> \n%-.10d\nouioui \n", numba);
//	i = printf("OG test : %x \n", numba);
//	printf("%d i == %d\n", numba, i);
	//	return (0);
}
