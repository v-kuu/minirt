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

static t_hit	finite_hit(float t, t_ray ray, t_cylinder cyl);
static t_hit	solve_hit(float t1, float t2, t_cylinder cyl, t_ray ray);
static t_hit	circle_intersection(t_cylinder cyl, t_ray ray, int dir);

t_hit	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_vec3			displacement_vec;
	float			squares[2];
	float			projection;
	float			discriminant;
	float			t[2];

	cyl.diameter /= 2;
	ray.origin = subtract_vec(ray.origin, cyl.center);
	ray = rotate_ray(ray, cyl.q_axis);
	displacement_vec = subtract_vec((t_vec3){0, 0, 0}, ray.origin);
	squares[0] = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	projection = ray.direction.x * displacement_vec.x
		+ ray.direction.z * displacement_vec.z;
	squares[1] = pow(displacement_vec.x, 2) + pow(displacement_vec.z, 2)
		- pow(cyl.diameter, 2);
	discriminant = projection * projection - squares[0] * squares[1];
	if (discriminant < 0)
		return ((t_hit){.t = FLT_MAX});
	t[0] = (projection - sqrtf(discriminant)) / squares[0];
	t[1] = (projection + sqrtf(discriminant)) / squares[0];
	return (solve_hit(t[0], t[1], cyl, ray));
}

static t_hit	solve_hit(float t1, float t2, t_cylinder cyl, t_ray ray)
{
	t_hit	t_all[4];
	t_hit	closest;
	int		index;

	closest.t = FLT_MAX;
	t_all[0] = finite_hit(t1, ray, cyl);
	t_all[1] = finite_hit(t2, ray, cyl);
	t_all[2] = circle_intersection(cyl, ray, 1);
	t_all[3] = circle_intersection(cyl, ray, -1);
	index = -1;
	while (++index < 4)
		if (t_all[index].t < closest.t && t_all[index].t > 0)
			closest = t_all[index];
	closest.color = cyl.color;
	return (closest);
}

static t_hit	circle_intersection(t_cylinder cyl, t_ray ray, int dir)
{
	t_hit	ret;
	t_vec3	cap_point;
	float	temp;
	float	denominator;

	cap_point = (t_vec3){0, cyl.height / 2 * dir, 0};
	temp = dot_product(subtract_vec(cap_point, ray.origin),
			(t_vec3){0, dir, 0});
	denominator = dot_product(ray.direction, (t_vec3){0, 1 * dir, 0});
	if (fabs(denominator) < 1e-6)
		return ((t_hit){.t = FLT_MAX});
	ret.t = temp / denominator;
	if (vec_len(subtract_vec(ray_at(ray, ret.t), cap_point)) > cyl.diameter)
		return ((t_hit){.t = FLT_MAX});
	ret.normal = rotate_by_quat(inverse_quat(cyl.q_axis), (t_vec3){0, dir, 0});
	return (ret);
}

static t_hit	finite_hit(float t, t_ray ray, t_cylinder cyl)
{
	t_hit	ret;
	t_point	hit;

	hit = ray_at(ray, t);
	if (hit.y > cyl.height / 2 || hit.y < cyl.height / -2)
	{
		ret.t = FLT_MAX;
		return (ret);
	}
	ret.t = t;
	hit.y = 0;
	ret.normal = normalize(subtract_vec(hit, (t_vec3){0, 0, 0}));
	ret.normal = rotate_by_quat(inverse_quat(cyl.q_axis), ret.normal);
	return (ret);
}

void	calculate_cylinder_quats(t_objects *obj)
{
	int	index;

	index = -1;
	while (++index < obj->cyctr)
		obj->cy[index].q_axis = normalize_quat(create_rotation_quat(
					(t_vec3){0, 1, 0}, obj->cy[index].axis));
}
