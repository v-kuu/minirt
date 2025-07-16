/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:24:39 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/16 11:57:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	validate_coordination(t_vec3 *coords)
{
	if ((coords->x > MOL || coords->x < -MOL) || (coords->y > MOL
			|| coords->y < -MOL) || (coords->z > MOL || coords->z < -MOL))
	{
		return (ft_putstr_fd("Error\ncheck coordinates values\n", 2), false);
	}
	return (true);
}

bool	validate_orientation(t_vec3 *orinets)
{
	if ((orinets->x > 1.0f || orinets->x < -1.0f) || (orinets->y > 1.0f
			|| orinets->y < -1.0f) || (orinets->z > 1.0f || orinets->z < -1.0f))
	{
		return (ft_putstr_fd("Error\ncheck Orinetations vales\n", 2), false);
	}
	if ((orinets->x > MOL || orinets->x < -MOL) || (orinets->y > MOL
			|| orinets->y < -MOL) || (orinets->z > MOL || orinets->z < -MOL))
	{
		return (ft_putstr_fd("Error\ncheck Orinetations values\n", 2), false);
	}
	return (true);
}

bool	fill_in_orientations(t_data *data, int i, t_vec3 *orinets)
{
	char	**orientations;

	if (!commas_counter(data->lines[i].line[2]))
		return (false);
	orientations = ft_split(data->lines[i].line[2], ',');
	if (!orientations)
		return (ft_putstr_fd("Error\n Allocating memory failed\n", 2), false);
	if (!arguments_counter(orientations))
		return (ft_free_str_arr(orientations), false);
	orinets->x = ft_atof(orientations[0]);
	if (isnan(orinets->x))
		return (ft_free_str_arr(orientations), false);
	orinets->y = ft_atof(orientations[1]);
	if (isnan(orinets->y))
		return (ft_free_str_arr(orientations), false);
	orinets->z = ft_atof(orientations[2]);
	if (isnan(orinets->z))
		return (ft_free_str_arr(orientations), false);
	ft_free_str_arr(orientations);
	if (!validate_orientation(orinets))
		return (false);
	return (true);
}

bool	fill_in_coordinates(t_data *data, int i, t_vec3 *coords)
{
	char	**coordinates;

	if (!commas_counter(data->lines[i].line[1]))
		return (false);
	coordinates = ft_split(data->lines[i].line[1], ',');
	if (!coordinates)
		return (ft_putstr_fd("Error\n Allocating memory failed\n", 2), false);
	if (!arguments_counter(coordinates))
		return (ft_free_str_arr(coordinates), false);
	coords->x = ft_atof(coordinates[0]);
	if (isnan(coords->x))
		return (ft_free_str_arr(coordinates), false);
	coords->y = ft_atof(coordinates[1]);
	if (isnan(coords->y))
		return (ft_free_str_arr(coordinates), false);
	coords->z = ft_atof(coordinates[2]);
	if (isnan(coords->z))
		return (ft_free_str_arr(coordinates), false);
	ft_free_str_arr(coordinates);
	if (!validate_coordination(coords))
		return (false);
	return (true);
}

bool	fill_in_c_fov(t_data *data, int i, t_camera *c)
{
	c->fov = ft_atof(data->lines[i].line[3]);
	if (isnan(c->fov))
		exit_free_parsing(data);
	if (!(c->fov >= 0.0f && c->fov <= 180.0f))
		return (ft_putstr_fd("Error\ncheck fov value\n", 2), false);
	return (true);
}
