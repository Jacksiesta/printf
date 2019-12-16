/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:53:02 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 12:27:59 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	num;

	num = (int long)n;
	if (fd >= 0)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = -num;
		}
		if (num >= 10)
			ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
}
