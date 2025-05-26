/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:21:00 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 16:40:13 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t length)
{
	void	*result;

	result = destination;
	if ((!destination && !source) && length)
		return (0);
	if (destination < source)
	{
		while (length > 0)
		{
			*(char *)destination++ = *(char *)source++;
			length--;
		}
	}
	else
	{
		destination += (length - 1);
		source += (length - 1);
		while (length > 0)
		{
			*(char *)destination-- = *(char *)source--;
			length--;
		}
	}
	return (result);
}
