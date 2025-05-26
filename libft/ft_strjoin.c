/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:00:36 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 10:11:27 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	length;
	size_t	index;
	char	*joined;

	if (!prefix || !suffix)
		return (0);
	length = ft_strlen(prefix) + ft_strlen(suffix);
	joined = (char *)malloc(length * sizeof(char) + 1);
	if (joined == 0)
		return (0);
	index = 0;
	while (*prefix != 0)
	{
		joined[index] = *prefix;
		index++;
		prefix++;
	}
	while (*suffix != 0)
	{
		joined[index] = *suffix;
		index++;
		suffix++;
	}
	joined[index] = 0;
	return (joined);
}
