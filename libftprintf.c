/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/21 10:29:35 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*init_struct(t_flag *flag)
{
	flag->zero_flag = 0; // pour pas avoir de valeur residuelle
	flag->minus_flag = 0;
	flag->width = 0;
	flag->precision = -1;
	return (0);
}

// example () //example of how to use structure
// {
// 	t_flag	*struc;
//
// 	struc = (t_flag*)malloc(sizeof(t_flag)); // place allouee pour la structure
// 	struc = init_struc(struc); //
// 	if (struc->zero_flag == 1) // either exists or doesn't (1 or 0)
// 		return (0);
//	else
// }

//int		param_zero_flag(va_list ap, char *str) // value of flag
//{
//	int 	x;
//	char	*str_param;
//	int		param;
//
//	x = 0;
//	while (str[x] != '0')
//		x++;
//	x = x + 1;
//	if (str[x] == '*')
//		param = va_arg(ap, int);
//	while (str[x] >= 0 && str[x] <= 9)
//	{
//		*str_param = str[x];
//		str_param++;
//		x++;
//	}
//	param = ft_atoi(str_param);
//	return (param);
//}

char	*parser(char *str, t_flag *flag) // activates flags
{
    int x;

    x = 0;
    while (str[x] == '-')
    {
        flag->minus_flag = 1;
        x++;
    }
    while (str[x] == '0')
    {
        flag->zero_flag = 1;
        x++;
    }
    else if (str[x] == '*' || (str[x] >= '0' && str[x] <= '9'))
    {
        if (str[x] == '*')
            flag->width = va_arg(ap, int);
        else
            flag->width = ft_atoi(&str[x], &x);
    }
    else if (str[x] == '.')
    {
        x++;
        if (str[x] == '*')
            flag->precision = va_arg(ap, int);
        else
            flag->precision = ft_atoi(&str[x], &x);
    }
    if (flag->precision || flag->minus_flag)
        flag->zero_flag = 0;
    return (0);
}

char    *convers_d(va_list ap)
{


}


char	ft_s(va_list ap)
{
	char	*value;
	write(1, value, ft_strlen(value));
	return (0);
}

char	ft_c(va_list ap)
{
	char	a;

	a = va_arg(ap, int);
	write(1, &a, 1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_lenght_hex(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		x++;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / 16;
		x++;
	}
	return (x);
}

char	ft_hex_conversion(int n)
{
	int		mod;
	char	*hex;

	if (!(hex = ft_strdup("0123456789abcdef")))
		return (0);
	if (n)
	{
		mod = n % 16;
		return (hex[mod]);
	}
	return (0);
}

char	*ft_x(va_list ap)
{
	int		num;
	int		size;
	char	*new;

	num = va_arg(ap, int);
	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

char	ft_hex_maj_conversion(int n)
{
	int		mod;
	char	*maj_hex;

	maj_hex = ft_strdup("0123456789ABCDEF");
	while (n)
	{
		mod = n % 16;
		return (maj_hex[mod]);
	}
	return (0);
}

char	*ft_xx(va_list ap)
{
	unsigned int		num;
	int		size;
	char	*new;

	num = va_arg(ap, unsigned int);
	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_maj_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

//int		ft_p(va_list ap)
//{
//	//cast in void*
//}

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

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
		    len = size_percent(coucou);
			if (coucou[x + len - 1] == 's')
				ft_s(ap);
			if (coucou[x + len - 1] == 'c')
				ft_c(ap);
			if (coucou[x + len - 1] == 'd' || coucou[x + len - 1] == 'i')
				ft_d(ap);
			if (coucou[x + len - 1] == 'x')
				ft_x(ap);
			if (coucou[x + len - 1] == 'X')
				ft_xx(ap);
			if (coucou[x + len - 1] == 'u')
				ft_u(ap);
			x = x + 2;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{
	int		numba = 45;
	ft_printf("hex test : %x \n", numba);
	printf("OG test : %x \n", numba);
	printf("%d\n", numba);
	//	return (0);
}
