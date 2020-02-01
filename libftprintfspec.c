/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfspec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:21:40 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/01 21:37:11 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			search_for(char c, char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] == c)
			return (0);
		x++;	
	}
	return (1);
}

char 	*pad_maker(char c, int len)
{
	char 	*pad;
	int		x;

	x = 0;
	if (!(pad = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
	{
		pad[x] = c;
		len--;
		x++;
	}
	pad[x] = '\0';
	return (pad);
}

void	ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

char	ft_s(va_list ap)
{
    char	*value;
    value = va_arg(ap, char*);
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
        num = num / 10;
        x++;
    }
    return (x);
}

char	*ft_d(int num)
{
    int			size;
    int			sign;
    char		*new;

    if (num == -2147483648)
        return (ft_strdup("-2147483648"));
    sign = (num < 0) ? 1 : 0;
	size = ft_lenght_int(num);
    num = (num < 0) ? -num : num;
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
    return (new);
}

int		ft_u(va_list ap)
{
    unsigned int	num;
    int				size;
    char			*new;

    num = va_arg(ap, unsigned int);
    size = ft_lenght_int(num);
    if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
        return (0);
    new[size] = '\0';
    while (size-- > 0)
    {
        new[size] = (num % 10) + '0';
        num = num / 10;
    }
    ft_putstr(new);
    return (1);
}

char	*ft_p(va_list ap)
{	
	long long unsigned int	address;

	address = va_arg(ap, long long unsigned int);
	printf("address is %llu", address);
	return (0);
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
//}
