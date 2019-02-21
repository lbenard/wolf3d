/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:40:07 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 09:24:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *list;
	t_list *cpy;

	tmp = f(lst);
	if (!(list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	cpy = list;
	while (lst)
	{
		tmp = f(lst);
		if (!(list->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		list = list->next;
		lst = lst->next;
	}
	return (cpy);
}
