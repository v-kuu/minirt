/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:01:14 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 15:01:15 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	ft_clamp(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_vec3	reflect_at(t_vec3 in_v, t_vec3 light_n)
{
	float	dot;

	dot = dot_product(in_v, light_n);
	return (subtract_vec(in_v, scale_vec(light_n, 2 * dot)));
}

t_rgbcolor	lighting_shadow(t_objects *obj, t_rgbcolor obj_color)
{
	t_rgbcolor	ambient;

	ambient = multiply_colors(normalize_color(obj_color),
			normalize_color(obj->a.color));
	ambient = multiply_color_by(ambient, obj->a.ratio);
	return (color_clamping(ambient));
}

bool	is_shadowed(t_objects *obj, t_ray ray, float t_max)
{
	t_hit		hit;
	int			index;

	index = -1;
	while (++index < obj->spctr)
	{
		hit = sphere_intersection(obj->sp[index], ray);
		if (hit.t >= 0 && hit.t < t_max)
			return (true);
	}
	index = -1;
	while (++index < obj->plctr)
	{
		hit = plane_intersection(obj->pl[index], ray);
		if (hit.t >= 0 && hit.t < t_max)
			return (true);
	}
	index = -1;
	while (++index < obj->cyctr)
	{
		hit = cylinder_intersection(obj->cy[index], ray);
		if (hit.t >= 0 && hit.t < t_max)
			return (true);
	}
	return (false);
}
