/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:32 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 15:17:44 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	if (character == '\0')
		return ((char *)string + ft_strlen(string));
	while (*string)
	{
		if (*string == character)
			return ((char *)string);
		string++;
	}
	return (0);
}
