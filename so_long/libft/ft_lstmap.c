/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:24:44 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/19 16:32:04 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	if (!lst)
		return (0);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
	{
		ft_lstclear(&newlist, (*del));
		return (0);
	}
	newlist->next = ft_lstmap(lst->next, (*f), (*del));
	return (newlist);
}
