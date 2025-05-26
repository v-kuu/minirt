/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:51 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 13:21:08 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t	source_length;
	size_t	dest_length;

	source_length = ft_strlen(source);
	if (!destination && !size)
		return (source_length);
	dest_length = ft_strlen(destination);
	if (dest_length >= size)
		return (size + source_length);
	if (size - dest_length > source_length)
		ft_memcpy(destination + dest_length, source, source_length + 1);
	else
	{
		ft_memcpy(destination + dest_length, source, size - dest_length - 1);
		destination[size - 1] = 0;
	}
	return (source_length + dest_length);
}
