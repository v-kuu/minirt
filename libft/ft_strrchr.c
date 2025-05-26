/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:20:53 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 15:21:24 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	char	*result;

	result = 0;
	if (character == '\0')
		result = (char *)string + ft_strlen(string);
	else
	{
		while (*string)
		{
			if (*string == character)
				result = (char *)string;
			string++;
		}
	}
	return (result);
}
