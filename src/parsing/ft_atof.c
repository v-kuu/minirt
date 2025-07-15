/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:34:31 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/15 15:10:33 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	check_all_nums(char *str)
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

static void	handle_minues(int *sign, int *i)
{
	*sign = -1;
	(*i)++;
}

bool	check_overflow(char *str)
{
	char	*tmp;
	int		p_position;

	tmp = NULL;
	p_position = 0;
	if (ft_strlen(str) > 40)
		return (false);
	return (true);
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
		return (ft_putstr_fd("Error\nnon digits is in the str\n", 2), NAN);
	if (!check_overflow(str))
		return (ft_putstr_fd("Error\noverflow check your values\n", 2), NAN);
	if (str[0] == '-')
		handle_minues(&sign, &i);
	while (str[i] && str[i] != '.' && str[i] != '\n')
		numberconvert(&f, str, &i);
	if (str[i] == '.')
	{
		decimal_part = ft_substr(str, i + 1, ft_strlen(str) - 2);
		f = f + decimal_convert(decimal_part);
		free(decimal_part);
	}
	if (f > 1000.0f || f < -1000.0f)
		return (ft_putstr_fd("Error\nover than the float min or max.\n", 2), NAN);
	return (f * sign);
}
