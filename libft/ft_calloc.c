/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:02:11 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:07 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*area;
	size_t	buffer;

	if (elements == 0 || size == 0)
	{
		elements = 1;
		size = 1;
	}
	buffer = elements * size;
	if (buffer / size != elements)
		return (0);
	area = malloc(buffer);
	if (area == 0)
		return (0);
	ft_bzero(area, buffer);
	return (area);
}
