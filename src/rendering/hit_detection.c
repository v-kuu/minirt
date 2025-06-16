/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:55 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	sphere_intersection(t_sphere sphere, t_ray ray)
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
		return (-1.0);
	else
		return ((projection - sqrtf(discriminant)) / square_ray);
}

float plane_intersection(t_plane plane, t_ray ray)
{
	float	denom;
	t_vec3	diff;
	float	t;

	denom = dot_product(ray.direction, plane.normal);
	if (fabsf(denom) < 1e-6) // ray is parallel to the plane
		return (-1.0);

	diff = subtract_vec(plane.point, ray.origin);
	t = dot_product(diff, plane.normal) / denom;

	if (t < 0)
		return (-1.0); // plane is behind the ray
	return (t);
}