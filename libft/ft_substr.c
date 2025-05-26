/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:57:17 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 16:02:41 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t length)
{
	char	*substring;
	size_t	index;

	if (string == 0)
		return (0);
	if (ft_strlen(string) <= start)
		length = 0;
	substring = (char *)malloc(length * sizeof(char) + 1);
	if (substring == 0)
		return (0);
	index = 0;
	while (length > 0)
	{
		substring[index] = string[start];
		index++;
		start++;
		length--;
	}
	substring[index] = 0;
	return (substring);
}
