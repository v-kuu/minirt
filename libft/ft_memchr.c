/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:22:03 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 13:32:59 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *source, int character, size_t length)
{
	unsigned char	*haystack;
	unsigned char	needle;

	haystack = (unsigned char *)source;
	needle = character;
	while (length > 0)
	{
		if (*haystack == needle)
			return (haystack);
		haystack++;
		length--;
	}
	return (0);
}
