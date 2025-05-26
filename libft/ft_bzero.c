/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:59:29 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:18 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *area, size_t length)
{
	size_t			index;
	unsigned char	*writer;

	index = 0;
	writer = (unsigned char *)area;
	while (index < length)
	{
		writer[index] = 0;
		index++;
	}
}
