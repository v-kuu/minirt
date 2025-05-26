/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:42:29 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/08 12:25:36 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *node)
{
	t_list	*temp;

	if (list)
	{
		if (*list == 0)
			*list = node;
		else
		{
			temp = ft_lstlast(*list);
			temp->next = node;
		}
	}
}
