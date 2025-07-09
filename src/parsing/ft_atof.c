/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:34:31 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:37:39 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	check_all_nums(char *str)
{
	int	i;

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

float	ft_atof(char *str)
{
	float	f;
	int		i;
	char	*decimal_part;
	int		sign;

	sign = 1;
	i = 0;
	f = 0;
	if (!str)
		return (NAN);
	if (!check_all_nums(str))
		return (ft_putstr_fd("Error: non digits is in the str\n", 2), NAN);
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
	if (f > FLT_MAX || f < -FLT_MAX)
		return (ft_putstr_fd("Error over than the max float.\n", 2), NAN);
	return (f * sign);
}
