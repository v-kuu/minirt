/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:53:02 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/06 13:22:54 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*func)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!list || !func || !del)
		return (0);
	new = ft_lstnew(func(list->content));
	if (!new)
		return (0);
	temp = new;
	list = list->next;
	while (list)
	{
		temp->next = ft_lstnew(func(list->content));
		if (!temp->next)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		temp = temp->next;
		list = list->next;
	}
	temp->next = 0;
	return (new);
}
