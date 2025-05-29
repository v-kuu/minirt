/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:42:43 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:50 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray	pixel_ray(t_vec3 origin, t_viewp viewport, int x, int y)
{
	t_vec3	ray_direction;
	t_vec3	pixel_center;
	t_vec3	temp;

	viewport.delta_u = scale_vec(viewport.delta_u, x);
	viewport.delta_v = scale_vec(viewport.delta_v, y);
	temp = add_vec(viewport.delta_u, viewport.delta_v);
	pixel_center = add_vec(viewport.pixel_zero, temp);
	ray_direction = subtract_vec(pixel_center, origin);
	return ((t_ray){origin, ray_direction});
}

t_point	ray_at(t_ray ray, float hit)
{
	t_vec3	scaled_dir;

	scaled_dir = scale_vec(ray.direction, hit);
	return (add_vec(ray.origin, scaled_dir));
}
