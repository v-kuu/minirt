/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:27:46 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 15:40:10 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	unsigned char	*first_u;
	unsigned char	*second_u;

	first_u = (unsigned char *)first;
	second_u = (unsigned char *)second;
	while (length)
	{
		if (*first_u != *second_u)
			return (*first_u - *second_u);
		if (*first_u == 0)
			return (0);
		length--;
		first_u++;
		second_u++;
	}
	return (0);
}
