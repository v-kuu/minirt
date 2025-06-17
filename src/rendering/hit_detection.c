/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/17 13:23:37 by mkhlouf          ###   ########.fr       */
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

float	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_vec3	displacement_vec;
	float	square_ray;
	float	projection;
	float	square_dist;
	float	discriminant;

	displacement_vec = subtract_vec(cyl.center, ray.origin);
	square_ray = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	projection = ray.direction.x * displacement_vec.x
		+ ray.direction.z * displacement_vec.z;
	square_dist = pow(displacement_vec.x, 2) + pow(displacement_vec.z, 2)
		- pow(cyl.diameter, 2);
	discriminant = projection * projection - square_ray * square_dist;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((projection - sqrtf(discriminant)) / square_ray);
}

/*
Plane has normal vector to decide the direction, and a point.
the equation for the intersection point t is:
t = dot(plane_point - ray_origin, plane_normal) / dot(ray_direction,
		plane_normal);
fabs(denominator < 1e-6),
	this meand to check if it is near to zero so this avoind the zeoro divition.
*/
float	plane_intersection(t_plane plane, t_ray ray)
{
	float	temp;
	float	denominator;
	float	t;

	temp = dot_product(subtract_vec(plane.point, ray.origin), plane.normal);
	denominator = dot_product(ray.direction, plane.normal);
	if (fabs(denominator) < 1e-6)
		return (-1.0);
	else
		t = temp / denominator;
	if (t < 0)
		return (-1.0);
	return (t);
}
