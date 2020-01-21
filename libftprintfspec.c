/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfspec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:21:40 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/21 13:21:44 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
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