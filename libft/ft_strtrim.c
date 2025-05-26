/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:12:39 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 11:14:41 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scanner(char suspect, char const *set);

char	*ft_strtrim(char const *string, char const *set)
{
	size_t	length;
	char	*trimmed;

	if (!string || !set)
		return (0);
	length = ft_strlen(string);
	while (length > 0 && ft_scanner(string[length - 1], set))
		length--;
	while (length > 0 && ft_scanner(*string, set))
	{
		length--;
		string++;
	}
	trimmed = (char *)malloc(length * sizeof(char) + 1);
	if (trimmed == 0)
		return (0);
	ft_strlcpy(trimmed, string, length + 1);
	return (trimmed);
}

static int	ft_scanner(char suspect, char const *set)
{
	while (*set != 0)
	{
		if (suspect == *set)
			return (1);
		set++;
	}
	return (0);
}
