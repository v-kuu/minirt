/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:44:22 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/05 12:08:07 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int number, int file_descriptor)
{
	long	input;

	input = number;
	if (input < 0)
	{
		write(file_descriptor, "-", 1);
		if (input == -2147483648)
		{
			write(file_descriptor, "2", 1);
			ft_putnbr_fd(147483648, file_descriptor);
			return ;
		}
		input *= -1;
	}
	if (input > 9)
		ft_putnbr_fd(input / 10, file_descriptor);
	ft_putchar_fd(input % 10 + 48, file_descriptor);
}
