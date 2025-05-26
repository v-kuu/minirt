/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:17:24 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/29 14:20:18 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(unsigned char character)
{
	if ((character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122))
		return (1);
	else if (character >= 48 && character <= 57)
		return (1);
	else
		return (0);
}
