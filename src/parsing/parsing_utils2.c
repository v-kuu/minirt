/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:30:41 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/16 11:56:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	check_overflow(char *str)
{
	if (ft_strlen(str) > 40)
		return (false);
	return (true);
}

bool	arguments_counter(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i != 3)
		return (ft_putstr_fd("Error\nMust be 3 arguments.", 2), false);
	return (true);
}

bool	commas_counter(char *str)
{
	int	i;
	int	commas_counter;

	i = 0;
	commas_counter = 0;
	while (str[i])
	{
		if (str[i] == ',')
			commas_counter++;
		i++;
	}
	if (commas_counter != 2 || str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (ft_putstr_fd("Error\n 3 arguments, 2 commas only.", 2), false);
	return (true);
}

bool	dot_check(char *str)
{
	int	i;
	int	dot_counter;

	i = 0;
	dot_counter = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_counter++;
		i++;
	}
	if (dot_counter > 1)
		return (false);
	return (true);
}
