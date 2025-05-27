/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:05:28 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 15:23:10 by mkhlouf          ###   ########.fr       */
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
