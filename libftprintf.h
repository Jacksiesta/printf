/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:07:46 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/09 00:24:59 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "libft_for_printf/libft.h"

typedef struct		s_flag
{
	int 			zero;
	int 			minus;
	int				width;
	int				precision;
}					t_flag;

int	    printf(const char *coucou, ...);
char	*ft_d(int num);
char	ft_s(va_list ap);
char	ft_c(va_list ap);
char	*ft_u(unsigned int num);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_lenght_int(int num);
int		ft_lenght_hex(int num);
char	ft_hex_conversion(int n);
char	*ft_x(int num);
char	ft_hex_maj_conversion(int n);
char	*ft_xx(va_list ap);
char	*ft_p(va_list ap);
char	*pad_maker(char c, int len);
int		search_for(char c, const char *str);
char	*cropped_str(char *str, int len);
char	*convers_hex_low(va_list ap, t_flag *flag);
char	*add_char_to_str(char c, char *str, int i);
char	*ft_percent_alone(va_list ap, t_flag *flag);
char	*convers_d(va_list ap, t_flag *flag);
char	*convers_s_null(t_flag *flag);
char	*convers_s(va_list ap, t_flag *flag);
char	*convers_hex_zero(t_flag *flag);
char	*convers_hex(va_list ap, t_flag *flag);
char	*convers_hex_precision(t_flag *flag, int size, char *init);
char	*convers_hex_width(t_flag *flag, char *init, char *fn);

#endif
