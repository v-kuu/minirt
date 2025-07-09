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

t_ray	light_ray(t_hit hit, t_light light, t_point hit_point)
{
	t_ray	ret;

	ret.origin = add_vec(hit_point, scale_vec(hit.normal, 0.01f));
	ret.direction = normalize(subtract_vec(light.coordinates, ret.origin));
	return (ret);
}

t_point	ray_at(t_ray ray, float hit)
{
	t_vec3	scaled_dir;

	scaled_dir = scale_vec(ray.direction, hit);
	return (add_vec(ray.origin, scaled_dir));
}

float	t_from_point(t_point hit, t_ray ray)
{
	return (vec_len(subtract_vec(hit, ray.origin)) / vec_len(ray.direction));
}

t_ray	rotate_ray(t_ray ray, t_quaternion quat)
{
	quat = normalize_quat(quat);
	ray.origin = rotate_by_quat(quat, ray.origin);
	ray.direction = rotate_by_quat(quat, ray.direction);
	return (ray);
}
