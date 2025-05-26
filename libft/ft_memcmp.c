/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:35:04 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 13:56:27 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *first, const void *second, size_t length)
{
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *)first;
	two = (unsigned char *)second;
	if (length == 0)
		return (0);
	while (length > 0)
	{
		if (*one != *two)
			return (*one - *two);
		one++;
		two++;
		length--;
	}
	return (0);
}
