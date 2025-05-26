/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:31:38 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/15 17:44:04 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(long number);

int	ft_number_print(long number)
{
	int		total;
	long	temp;

	temp = number;
	total = 1;
	if (temp < 0)
	{
		temp *= -1;
		number *= -1;
		if (write(1, "-", 1) < 0)
			return (-1);
		total++;
	}
	while (temp > 9)
	{
		total++;
		temp /= 10;
	}
	if (ft_putnbr(number) < 0)
		return (-1);
	return (total);
}

static int	ft_putnbr(long number)
{
	if (number > 9)
		ft_putnbr(number / 10);
	if (write(1, &(char){number % 10 + 48}, 1) < 0)
		return (-1);
	return (0);
}
