/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:07:46 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/09 12:01:02 by jherrald         ###   ########.fr       */
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

typedef struct		s_list
{
	void			*flag;
	int				*width;
	int				*precision;
	struct s_list	*next;
}					t_list;

int	printf(const char *coucou, ...);

#endif
