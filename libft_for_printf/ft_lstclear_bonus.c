/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:10:28 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/06 12:17:19 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;
	t_list	*newnew;
	int		x;
	int		y;

	if (!*lst || !del)
		return ;
	if (!lst)
		return ;
	new = *lst;
	x = ft_lstsize(new);
	while (x-- > 0)
	{
		y = 0;
		new = *lst;
		while (new && y < x)
		{
			newnew = new;
			new = newnew->next;
			y++;
		}
		del(new->content);
		free(new);
	}
	*lst = NULL;
}
