/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:40:37 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 15:59:02 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *area, int byte, size_t length)
{
	size_t			index;
	unsigned char	*writer;

	writer = (unsigned char *)area;
	index = 0;
	while (index < length)
	{
		writer[index] = byte;
		index++;
	}
	return (area);
}
