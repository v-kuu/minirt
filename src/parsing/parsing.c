/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:37 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:29:56 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	parse_to_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
		{
			remove_white_spaces(data->read_lines[i]);
			data->lines[j].line = ft_split(data->read_lines[i], ' ');
			if (!data->lines[j].line)
				return (free_lines_arr(data->lines), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	parse_to_objects(t_data *data)
{
	int			i;

	i = 0;
	data->objects = ft_calloc(1, sizeof(t_objects));
	if (!data->objects)
		return (false);
	if (!malloc_all_objects(data))
		return (free(data->objects), false);
	while (data->lines[i].line)
	{
		if (ft_strcmp(data->lines[i].line[0], "A") == 0)
			case_a(data, data->objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "C") == 0)
			case_c(data, data->objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "L") == 0)
			case_l(data, data->objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "sp") == 0)
			case_sp(data, data->objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "pl") == 0)
			case_pl(data, data->objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "cy") == 0)
			case_cy(data, data->objects, i);
		i++;
	}
	return (true);
}

void	calculate_counters(t_data *data)
{
	int	i;

	i = 0;
	while (data->lines[i].line)
	{
		if (ft_strcmp(data->lines[i].line[0], "L") == 0)
			data->light_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "pl") == 0)
			data->pl_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "cy") == 0)
			data->cy_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "sp") == 0)
			data->sp_counter++;
		i++;
	}
}

bool	malloc_all_objects(t_data *data)
{
	data->objects->l = ft_calloc(data->light_counter, sizeof(t_light));
	if (!data->objects->l)
		return (false);
	data->objects->sp = ft_calloc(data->sp_counter, sizeof(t_sphere));
	if (!data->objects->sp)
		return (free(data->objects->l), false);
	data->objects->cy = ft_calloc(data->cy_counter, sizeof(t_cylinder));
	if (!data->objects->cy)
		return (free(data->objects->l), free(data->objects->sp), false);
	data->objects->pl = ft_calloc(data->pl_counter, sizeof(t_plane));
	if (!data->objects->pl)
	{
		return (free(data->objects->l), free(data->objects->sp),
			free(data->objects->cy), false);
	}
	return (true);
}

bool	parsing(t_data *data)
{
	data->lines_counter = not_empty_lines(data);
	data->lines = ft_calloc((data->lines_counter + 1), sizeof(t_s_lines));
	if (!data->lines)
		return (false);
	if (!parse_to_lines(data))
		return (false);
	if (!validation(data))
		return (free_lines_arr(data->lines), false);
	calculate_counters(data);
	if (!parse_to_objects(data))
		return (free_lines_arr(data->lines), false);
	return (ft_free_str_arr(data->read_lines), true);
}
