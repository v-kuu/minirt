/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:30:41 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/16 11:56:17 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	arr_count(char **arr)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int	not_empty_lines(t_data *data)
{
	int	i;
	int	lines_counter;

	i = 0;
	lines_counter = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
			lines_counter++;
		i++;
	}
	return (lines_counter);
}

void	free_lines_arr(t_s_lines *lines)
{
	int	i;

	i = 0;
	while (lines[i].line)
	{
		ft_free_str_arr(lines[i].line);
		lines[i].line = NULL;
		i++;
	}
	free(lines);
	lines = NULL;
}

void	remove_white_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == '\n' || line[i] == '\f'
			|| line[i] == '\r' || line[i] == '\v')
			line[i] = ' ';
		i++;
	}
}

bool	color_validation(t_rgbcolor *color)
{
	if (!(color->r >= 0.0f && color->r <= 255.0f))
		return (ft_putstr_fd("Error\ninvalid color red value.\n", 2), false);
	if (!(color->g >= 0.0f && color->g <= 255.0f))
		return (ft_putstr_fd("Error\ninvalid color green value.\n", 2), false);
	if (!(color->b >= 0.0f && color->b <= 255.0f))
		return (ft_putstr_fd("Error\ninvalid color blue value.\n", 2), false);
	return (true);
}
