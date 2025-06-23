/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_detection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:20:19 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/23 16:55:14 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static float	check_caps(float t1, float t2, t_cylinder cyl, t_ray ray);
static float	circle_intersection(t_cylinder cyl, t_ray ray, int dir);
static t_hit	hit_to_world(float t, t_ray ray, t_cylinder cyl);

t_hit	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_vec3			displacement_vec;
	float			squares[2];
	float			projection;
	float			discriminant;
	float			t;

	cyl.diameter /= 2;
	ray.origin = subtract_vec(ray.origin, cyl.center);
	ray = rotate_ray(ray, cyl.q_axis);
	ray.origin = add_vec(ray.origin, cyl.center);
	displacement_vec = subtract_vec(cyl.center, ray.origin);
	squares[0] = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	projection = ray.direction.x * displacement_vec.x
		+ ray.direction.z * displacement_vec.z;
	squares[1] = pow(displacement_vec.x, 2) + pow(displacement_vec.z, 2)
		- pow(cyl.diameter, 2);
	discriminant = projection * projection - squares[0] * squares[1];
	if (discriminant < 0)
		return ((t_hit){.t = -1.0f});
	t = check_caps(((projection - sqrtf(discriminant)) / squares[0]),
			(projection + sqrtf(discriminant) / squares[0]),
			cyl, ray);
	if (t < 0)
		return ((t_hit){.t = -1.0f});
	return (hit_to_world(t, ray, cyl));
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

static t_hit	hit_to_world(float t, t_ray ray, t_cylinder cyl)
{
	const t_point	local_hit = ray_at(ray, t);
	t_point			world_hit;
	t_hit			ret;

	world_hit = rotate_by_quat(inverse_quat(cyl.q_axis), local_hit);
	ray.origin = subtract_vec(ray.origin, cyl.center);
	ray = rotate_ray(ray, inverse_quat(cyl.q_axis));
	ray.origin = add_vec(ray.origin, cyl.center);
	ret.t = t_from_point(world_hit, ray);
	return (ret);
}
