/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:49 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:40:30 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	fill_in_b_ration(char *value, t_light *light)
{
	light->b_ratio = ft_atof(value);
	if (isnan(light->b_ratio))
		return (false);
	if (!(light->b_ratio >= 0.0 && light->b_ratio <= 1.0))
		return (false);
	return (true);
}

bool	fill_in_rgb(char *value, t_rgbcolor *color)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (!rgb)
		return (false);
	color->r = ft_atof(rgb[0]);
	color->g = ft_atof(rgb[1]);
	color->b = ft_atof(rgb[2]);
	ft_free_str_arr(rgb);
	if (isnan(color->r) || isnan(color->g) || isnan(color->b))
		return (false);
	if (!color_validation(color))
		return (false);
	return (true);
}

void	case_l(t_data *data, t_objects *objects, int i)
{
	if (arr_count(data->lines[i].line) != 4)
	{
		ft_putstr_fd("Error\nwrong arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->l[objects->lctr].coordinates))
		exit_free_parsing(data);
	if (!fill_in_b_ration(data->lines[i].line[2], &objects->l[objects->lctr]))
		exit_free_parsing(data);
	if (!fill_in_rgb(data->lines[i].line[3], &objects->l[objects->lctr].color))
		exit_free_parsing(data);
	objects->lctr++;
}

bool	validate_a(t_a_light a)
{
	if (!(a.ratio >= 0 && a.ratio <= 1))
		return (ft_putstr_fd(
				"Error\ninvalid Ambient light ratio.\n", 2), false);
	if (!color_validation(&a.color))
		return (false);
	return (true);
}

void	case_a(t_data *data, t_objects *objects, int i)
{
	char	**rgb;

	if (arr_count(data->lines[i].line) != 3)
	{
		ft_putstr_fd("Error\nwrong arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	objects->a.ratio = ft_atof(data->lines[i].line[1]);
	rgb = ft_split(data->lines[i].line[2], ',');
	if (!rgb)
	{
		ft_free_str_arr(rgb);
		exit_free_parsing(data);
	}
	objects->a.color.r = ft_atof(rgb[0]);
	objects->a.color.g = ft_atof(rgb[1]);
	objects->a.color.b = ft_atof(rgb[2]);
	if (isnan(objects->a.ratio) || isnan(objects->a.color.r)
		|| isnan(objects->a.color.g) || isnan(objects->a.color.b)
		|| !validate_a(objects->a))
	{
		ft_free_str_arr(rgb);
		exit_free_parsing(data);
	}
	ft_free_str_arr(rgb);
}
