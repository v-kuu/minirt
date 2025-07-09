/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:24:39 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:24:41 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	validate_coordination(t_vec3 *coords)
{
	if ((coords->x > MOL || coords->x < -MOL) || (coords->y > MOL || coords->y
			< -MOL) || (coords->z > MOL || coords->z < -MOL))
	{
		return (ft_putstr_fd("Error\ncheck coordinates values\n", 2), false);
	}
	return (true);
}

bool	validate_orientation(t_vec3 *orinets)
{
	if ((orinets->x > 1.0f || orinets->x < -1.0f)
		|| (orinets->y > 1.0f || orinets->y < -1.0f)
		|| (orinets->z > 1.0f || orinets->z < -1.0f))
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

	orientations = ft_split(data->lines[i].line[2], ',');
	if (!orientations)
		exit_free_parsing(data);
	orinets->x = ft_atof(orientations[0]);
	orinets->y = ft_atof(orientations[1]);
	orinets->z = ft_atof(orientations[2]);
	ft_free_str_arr(orientations);
	if (isnan(orinets->x) || isnan(orinets->y) || isnan(orinets->z))
		return (false);
	if (!validate_orientation(orinets))
		return (false);
	return (true);
}

bool	fill_in_coordinates(t_data *data, int i, t_vec3 *coords)
{
	char	**coordinates;

	coordinates = ft_split(data->lines[i].line[1], ',');
	if (!coordinates)
		return (false);
	coords->x = ft_atof(coordinates[0]);
	coords->y = ft_atof(coordinates[1]);
	coords->z = ft_atof(coordinates[2]);
	ft_free_str_arr(coordinates);
	if (isnan(coords->x) || isnan(coords->y) || isnan(coords->z))
		return (false);
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
