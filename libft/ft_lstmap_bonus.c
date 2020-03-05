/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:03:28 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:03:29 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Marche pas aux tests parce que del est protected
** (enlever le '|| !del' ligne 24 pour test)
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *alst;

	if (!lst || !del)
		return (NULL);
	if (!f)
		return (lst);
	if (!(alst = ft_lstnew(f(lst->content))))
		return (NULL);
	if (lst->next)
	{
		if (!(alst->next = ft_lstmap(lst->next, f, del)))
		{
			ft_lstdelone(lst, del);
			return (NULL);
		}
	}
	else
		alst->next = NULL;
	return (alst);
}
