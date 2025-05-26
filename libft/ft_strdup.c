/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:56 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:07 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	elements;
	char	*duplicate;

	elements = ft_strlen(string) + 1;
	duplicate = (char *)malloc(elements * sizeof(char));
	if (duplicate == 0)
		return (0);
	ft_strlcpy(duplicate, string, elements);
	return (duplicate);
}
