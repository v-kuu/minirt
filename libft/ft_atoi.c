/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:48:27 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/30 15:01:25 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*string == ' ' || *string == '\f' || *string == '\n'
		|| *string == '\r' || *string == '\t' || *string == '\v')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (*string >= 48 && *string <= 57)
	{
		result = (result * 10) + *string - 48;
		string++;
	}
	result *= sign;
	return (result);
}
