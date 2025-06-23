/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:50:28 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/23 17:50:51 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_hit	sphere_intersection(t_sphere sphere, t_ray ray)
{
	t_vec3	displacement_vec;
	float	square_ray;
	float	projection;
	float	square_dist;
	float	discriminant;

	displacement_vec = subtract_vec(sphere.center, ray.origin);
	square_ray = dot_product(ray.direction, ray.direction);
	projection = dot_product(ray.direction, displacement_vec);
	square_dist = dot_product(displacement_vec, displacement_vec)
		- sphere.radius * sphere.radius;
	discriminant = projection * projection - square_ray * square_dist;
	if (discriminant < 0)
		return ((t_hit){.t = -1.0f});
	else
		return (t_hit){.t = (projection - sqrtf(discriminant)) / square_ray};
}

/*
Plane has normal vector to decide the direction, and a point.
the equation for the intersection point t is:
t = dot(plane_point - ray_origin, plane_normal) / dot(ray_direction,
		plane_normal);
fabs(denominator < 1e-6),
	this meand to check if it is near to zero so this avoind the zeoro divition.
*/
t_hit	plane_intersection(t_plane plane, t_ray ray)
{
	float	temp;
	float	denominator;
	float	t;
	t_hit	hit;

	temp = dot_product(subtract_vec(plane.point, ray.origin), plane.normal);
	denominator = dot_product(ray.direction, plane.normal);
	if (fabs(denominator) < 1e-6)
		return ((t_hit){.t = -1.0f});
	else
		t = temp / denominator;
	if (t < 0)
		return ((t_hit){.t = -1.0f});
	hit.t = t;
	return (hit);
}
