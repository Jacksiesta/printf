/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:42:22 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/06 14:18:08 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*answ;

	if (!lst)
		return (NULL);
	if (!f)
		return ((t_list *)lst);
	if (!(answ = ft_lstnew(f(lst->content))))
		return (NULL);
	res = answ;
	while (lst->next)
	{
		lst = lst->next;
		if (!(answ->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&res, del);
		answ = answ->next;
	}
	return (res);
}
