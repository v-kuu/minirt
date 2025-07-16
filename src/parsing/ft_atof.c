/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:34:31 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/16 12:21:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	check_all_nums(char *str)
{
	int	i;

	i = 0;
	if (!dot_check(str))
		return (false);
	if (ft_strlen(str) != 1 && (str[0] == '.' || str[ft_strlen(str)
				- 1] == '.'))
		return (false);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isfloat(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	numberconvert(float *f, char *str, int *i)
{
	*f = *f * 10;
	(*f) += str[*i] - '0';
	(*i)++;
}

static float	decimal_convert(char *decimal_part)
{
	int		j;
	float	d;

	j = 0;
	d = 0;
	if (!decimal_part)
		return (NAN);
	while (decimal_part[j])
	{
		d = d * 10;
		d += decimal_part[j] - '0';
		j++;
	}
	d = d / pow(10, (j));
	return (d);
}

static void	handle_minus(int *sign, int *i)
{
	*sign = -1;
	(*i)++;
}

float	ft_atof(char *str)
{
	float	f;
	int		i;
	char	*decimal_part;
	int		sign;

	sign = 1;
	i = 0;
	f = 0;
	if (!str || !check_all_nums(str))
		return (ft_putstr_fd("Error\nCheck the values\n", 2), NAN);
	if (!check_overflow(str))
		return (ft_putstr_fd("Error\noverflow check your values\n", 2), NAN);
	if (str[0] == '-')
		handle_minus(&sign, &i);
	while (str[i] && str[i] != '.' && str[i] != '\n')
		numberconvert(&f, str, &i);
	if (str[i] == '.')
	{
		decimal_part = str + i + 1;
		f = f + decimal_convert(decimal_part);
	}
	if (f > 1000.0f || f < -1000.0f)
		return (ft_putstr_fd("Error\nover than float min or max.\n", 2), NAN);
	return (f * sign);
}
