/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfspec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:21:40 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/23 14:12:03 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*cropped_str(char *str, int len)
{
	char	*final;
	int		x;

	x = 0;
	if (!(final = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		final[x] = str[x];
		x++;
	}
	final[x] = '\0';
	return (final);
}

char		*add_char_to_str(char c, char *str, int i)
{
	int		x;
	char	*final;

	if (!(final = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	x = 0;
	if (!str)
		return (NULL);
	if (i == 0)
	{
		final[0] = c;
		x = 1;
	}
	while (*str)
	{
		final[x] = *str;
		x++;
		str++;
	}
	if (i == 1)
		final[x++] = c;
	final[x] = '\0';
	return (final);
}

int			search_for(char c, const char *str)
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

char	*pad_maker(char c, int len)
{
	char	*pad;
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
	if (*str == '\0')
	{
		ft_putchar('\0');
	}
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

int		ft_lenght_unsigned_int(long long unsigned int num)
{
	int	x;

	x = 0;
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

char	*ft_u(long long unsigned int num)
{
	int				size;
	char			*new;

	if (num == 4294967295)
		return (ft_strdup("4294967295"));
	if (num == 0)
		return (0);
	size = ft_lenght_unsigned_int(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (new);
}

int		ft_lenght_hex(long long unsigned int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		x++;
	}
	return (x);
}

char	ft_hex_conversion(long long unsigned int n)
{
	long long unsigned int		mod;
	char						*hex;

	hex = "0123456789abcdef";
	//	if (!(hex = ft_strdup("0123456789abcdef")))
	//      return (0);
	if (n)
	{
		mod = n % 16;
		return (hex[mod]);
	}
	return (0);
}

char	*ft_x(long long unsigned int num)
{
	int		size;
	char	*new;

	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_conversion(num);
		num = num / 16;
	}
	// ft_putstr(new);
	return (new);
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
	int					size;
	char				*new;

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
