/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:47:28 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/15 17:47:55 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_string_print(const char *string)
{
	int	index;

	index = 0;
	if (!string)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (string[index])
	{
		if (write(1, &string[index], 1) < 0)
			return (-1);
		index++;
	}
	return (index);
}
