/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:18:00 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/15 17:44:49 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_hex(uintptr_t number, char specifier);
static int	ft_digit_count(uintptr_t number);

int	ft_hex_print(uintptr_t number, char specifier)
{
	int	total;

	total = 0;
	if (specifier == 'p')
	{
		if (number == 0)
		{
			if (write(1, "(nil)", 5) < 0)
				return (-1);
			return (5);
		}
		else
		{
			if (write(1, "0x", 2) < 0)
				return (-1);
			total += 2;
		}
	}
	total += ft_digit_count(number);
	if (ft_recursive_hex(number, specifier) < 0)
		return (-1);
	return (total);
}

static int	ft_recursive_hex(uintptr_t number, char specifier)
{
	if (number > 15)
		ft_recursive_hex(number / 16, specifier);
	if (number % 16 < 10)
	{
		if (write(1, &(char){number % 16 + 48}, 1) < 0)
			return (-1);
	}
	else
	{
		if (specifier == 'X')
		{
			if (write(1, &(char){number % 16 + 55}, 1) < 0)
				return (-1);
		}
		else
			if (write(1, &(char){number % 16 + 87}, 1) < 0)
				return (-1);
	}
	return (0);
}

static int	ft_digit_count(uintptr_t number)
{
	int	total;

	total = 1;
	while (number > 15)
	{
		total++;
		number /= 16;
	}
	return (total);
}
