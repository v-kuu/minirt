/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:56:02 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 12:59:17 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_digit_count(long integer);

char	*ft_itoa(int integer)
{
	char	*string;
	int		sign;
	int		size;
	long	number;

	number = integer;
	sign = (number < 0);
	size = ft_digit_count(number);
	if (sign)
		number *= -1;
	string = (char *)ft_calloc(size + sign + 1, sizeof(char));
	if (string == 0)
		return (0);
	if (integer == 0)
		string[0] = '0';
	while (number > 0)
	{
		string[size - 1] = number % 10 + 48;
		size--;
		number /= 10;
	}
	if (sign)
		string[0] = '-';
	return (string);
}

static long	ft_digit_count(long integer)
{
	long	count;

	count = 1;
	if (integer < 0)
	{
		integer *= -1;
		count++;
	}
	while (integer > 9)
	{
		count++;
		integer /= 10;
	}
	return (count);
}
