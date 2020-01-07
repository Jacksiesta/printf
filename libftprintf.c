/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/07 15:46:15 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_s(va_list ap)
{
	char	*value;

	value = va_arg(ap, char *);
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

int		ft_lenght_int(int num)
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
		num  /= 10;
		x++;
	}
	printf("x is %d\n", x);
	return (x);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_d(va_list ap)
{
	int			num;
	int			size;
	int			sign;
	char		*new;

	num = va_arg(ap, int);
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	size = ft_lenght_int(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	if (sign == 1)
		new[0] = '-';
	while (size-- > sign)
	{
		new[size] = (num % 10) + '0';
		num = num / 10;
	}
	ft_putstr(new);
	return (NULL);
}

char	*ft_hex_conversion(int n)
{
	int		mod;
	char	*hex;

	hex = ft_strdup("0123456789abcdef");
	while (n)
	{
		mod = (n % 16) + '0';
		return (&hex[mod]);
	}
	return (0);
}

char	*ft_x(va_list ap)
{
	int		num;
	int		size;
	char	*new;

	num = va_arg(ap, int);
	size = ft_lenght_int(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 1)
	{
		new[size] = *ft_hex_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

char	*ft_hex_maj_conversion(int n)
{
	char	*maj_hex;

	maj_hex = ft_strdup("0123456789ABCDEF");
	while (n)
	{
		return (&maj_hex[n % 16]);
	}
	return (0);
}

char	*ft_xx(va_list ap)
{
	unsigned int		num;
	int		size;
	char	*new;

	num = va_arg(ap, unsigned int);
	size = ft_lenght_int(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 1)
	{
		new[size] = *ft_hex_maj_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

int		ft_printf(const char *coucou, ...)
{
	int		x;
	va_list	ap;

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			if (coucou[x + 1] == 's')
				ft_s(ap);
			if (coucou[x + 1] == 'c')
				ft_c(ap);
			if (coucou[x + 1] == 'd' || coucou[x + 1] == 'i')
				ft_d(ap);
			if (coucou[x + 1] == 'x')
				ft_x(ap);
			if (coucou[x + 1] == 'X')
				ft_xx(ap);
			x = x + 2;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{
//	char 	*temp = "kikouuuu";
//	char	*oups = "DEUX";
//	char	a = 'B';
	int		numba = 100;
	ft_printf("hex test : %x \n", numba);
//	ft_printf("un : %s troie \n", oups);
//	ft_printf("number test = %d nono \n", numba);
	//printf("what : %s WHAT \n", oups);
	//printf("coucoucou %.4s", oups);
	return (0);
}
