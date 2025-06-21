/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/21 13:28:47 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static float	check_caps(float t1, float t2, t_cylinder cyl, t_ray ray);
static float	circle_intersection(t_cylinder cyl, t_ray ray, int dir);

t_hit	sphere_intersection(t_objects *obj,  t_sphere sphere, t_ray ray)
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
	{
		t_hit hit;

		hit.t = (projection - sqrtf(discriminant)) / square_ray;
		hit.normal = sp_normal_at(sphere,ray_at(ray,hit.t));	
		hit.color = shading_visual(shading_vectors2(obj, sphere.color, hit));
		hit.ray = ray;
		return (hit);
	}
}

t_hit	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_vec3	displacement_vec;
	float	square_ray;
	float	projection;
	float	square_dist;
	float	discriminant;

	cyl.diameter /= 2;
	displacement_vec = subtract_vec(cyl.center, ray.origin);
	square_ray = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	projection = ray.direction.x * displacement_vec.x
		+ ray.direction.z * displacement_vec.z;
	square_dist = pow(displacement_vec.x, 2) + pow(displacement_vec.z, 2)
		- pow(cyl.diameter, 2);
	discriminant = projection * projection - square_ray * square_dist;
	if (discriminant < 0)
		return ((t_hit){.t = -1.0f});
	return ((t_hit){.t = check_caps(((projection - sqrtf(discriminant)) / square_ray),
			(projection + sqrtf(discriminant) / square_ray),
			cyl, ray), .ray = ray});
	// i need the cylindar normal.
}

/*
Plane has normal vector to decide the direction, and a point.
the equation for the intersection point t is:
t = dot(plane_point - ray_origin, plane_normal) / dot(ray_direction,
		plane_normal);
fabs(denominator < 1e-6),
	this meand to check if it is near to zero so this avoind the zeoro divition.
*/
t_hit	plane_intersection(t_objects *obj, t_plane plane, t_ray ray)
{
	float	temp;
	float	denominator;
	float	t;
	t_hit hit;
	
	temp = dot_product(subtract_vec(plane.point, ray.origin), plane.normal);
	denominator = dot_product(ray.direction, plane.normal);
	if (fabs(denominator) < 1e-6)
		return ((t_hit){.t = -1.0f});
	else
		t = temp / denominator;
	if (t < 0)
		return ((t_hit){.t = -1.0f});	
	return ((t_hit){.t = t,.normal = plane.normal, .ray = ray, .color = shading_visual(shading_vectors2(obj, plane.color, hit))});
}

static float	check_caps(float t1, float t2, t_cylinder cyl, t_ray ray)
{
	float	t_all[4];
	float	closest;
	int		index;
	
	closest = FLT_MAX;
	t_all[0] = t1;
	if (ray_at(ray, t_all[0]).y > cyl.height / 2
		|| ray_at(ray, t_all[0]).y < cyl.height / -2)
		t_all[0] = -1;
	t_all[1] = t2;
	if (ray_at(ray, t_all[1]).y > cyl.height / 2
		|| ray_at(ray, t_all[1]).y < cyl.height / -2)
		t_all[1] = -1;
	t_all[2] = circle_intersection(cyl, ray, 1);
	t_all[3] = circle_intersection(cyl, ray, -1);
	index = 0;
	while (index < 4)
	{
		if (t_all[index] >= 0 && t_all[index] < closest)
			closest = t_all[index];
		index++;
	}
	if (closest == FLT_MAX)
		closest = -1.0;
	return (closest);
}

static float	circle_intersection(t_cylinder cyl, t_ray ray, int dir)
{
	t_vec3	cap_point;
	float	temp;
	float	denominator;
	float	t;

	cap_point = (t_vec3){cyl.center.x, cyl.height / 2 * dir, cyl.center.z};
	temp = dot_product(subtract_vec(cap_point, ray.origin),
			(t_vec3){0, 1 * dir, 0});
	denominator = dot_product(ray.direction, (t_vec3){0, 1 * dir, 0});
	if (fabs(denominator) < 1e-6)
		t = -1.0;
	else
	{
		t = temp / denominator;
		if (vec_len(subtract_vec(ray_at(ray, t), cap_point)) > cyl.diameter)
			t = -1.0;
	}
	return (t);
}
