/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:49 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/16 11:56:29 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	fill_in_b_ration(char *value, t_light *light)
{
	light->b_ratio = ft_atof(value);
	if (isnan(light->b_ratio))
		return (false);
	if (!(light->b_ratio >= 0.0 && light->b_ratio <= 1.0))
		return (ft_putstr_fd("Error\nmust be [0,1]\n", 2), false);
	return (true);
}

bool	fill_in_rgb(char *value, t_rgbcolor *color)
{
	char	**rgb;

	rgb = NULL;
	if (!commas_counter(value))
		return (ft_free_str_arr(rgb), false);
	rgb = ft_split(value, ',');
	if (!rgb)
		return (false);
	if (!arguments_counter(rgb))
		return (ft_free_str_arr(rgb), false);
	color->r = ft_atof(rgb[0]);
	if (isnan(color->r))
		return (ft_free_str_arr(rgb), false);
	color->g = ft_atof(rgb[1]);
	if (isnan(color->g))
		return (ft_free_str_arr(rgb), false);
	color->b = ft_atof(rgb[2]);
	if (isnan(color->b))
		return (ft_free_str_arr(rgb), false);
	ft_free_str_arr(rgb);
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
	if (!(a.ratio >= 0.0f && a.ratio <= 1.0f))
		return (ft_putstr_fd("Error\ninvalid Ambient light ratio.\n", 2),
			false);
	return (true);
}

void	case_a(t_data *data, t_objects *objects, int i)
{
	if (arr_count(data->lines[i].line) != 3)
	{
		ft_putstr_fd("Error\nwrong arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	objects->a.ratio = ft_atof(data->lines[i].line[1]);
	if (isnan(objects->a.ratio) || !validate_a(objects->a))
		exit_free_parsing(data);
	if (!fill_in_rgb(data->lines[i].line[2], &objects->a.color))
		exit_free_parsing(data);
}
