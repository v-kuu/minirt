/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:05:28 by vkuusela          #+#    #+#             */
/*   Updated: 2025/01/28 12:05:35 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_str_arr(char **array)
{
	int	index;

	if (!array)
		return (NULL);
	index = 0;
	while (array[index])
	{
		ft_free((void **)&array[index]);
		index++;
	}
	free(array);
	array = NULL;
	return (NULL);
}
