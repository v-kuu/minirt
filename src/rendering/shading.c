/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:05:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 15:09:14 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_vec3	sp_normal_at(t_sphere sphere, t_vec3 point)
{
	return (normalize(subtract_vec(point, sphere.center)));
}

t_rgbcolor	color_clamping(t_rgbcolor color)
{
	color.r = ft_clamp(color.r, 0.0f, 1.0f);
	color.g = ft_clamp(color.g, 0.0f, 1.0f);
	color.b = ft_clamp(color.b, 0.0f, 1.0f);
	return (color);
}

void	light_calculation(t_lights *light, t_phong *phong, t_light *light_obj)
{
	if (light->epsilon < 0)
	{
		light->diffuse = (t_rgbcolor){0, 0, 0};
		light->specular = (t_rgbcolor){0, 0, 0};
	}
	else
	{
		light->diffuse = multiply_color_by(light->effective_color,
				light->epsilon);
		light->epsilon = 0;
		light->epsilon = dot_product(phong->reflect_v, phong->eye_v);
		if (light->epsilon > 0)
		{
			light->factor = powf(light->epsilon, SHININESS);
			light->specular = multiply_color_by(
					normalize_color(light_obj->color),
					light->factor * light_obj->b_ratio * SPECULAR);
		}
		else
			light->specular = (t_rgbcolor){0, 0, 0};
	}
}

static t_rgbcolor	lighting(t_objects *obj, t_rgbcolor obj_col, t_phong phong)
{
	t_lights	light;

	light.effective_color = multiply_color_by(normalize_color(obj_col),
			obj->l[0].b_ratio);
	light.ambient = multiply_colors(normalize_color(obj_col),
			normalize_color(obj->a.color));
	light.ambient = multiply_color_by(light.ambient, obj->a.ratio);
	light.epsilon = dot_product(phong.light_v, phong.normal_v);
	light_calculation(&light, &phong, &obj->l[0]);
	light.final = add_colors(add_colors(light.ambient, light.diffuse),
			light.specular);
	return (color_clamping(light.final));
}

t_rgbcolor	shading_vectors(t_objects *obj, t_hit hit)
{
	t_phong	phong;
	t_vec3	hit_point;
	t_ray	ray;
	float	t_max;

	hit_point = ray_at(hit.ray, hit.t);
	ray = light_ray(hit, obj->l[0], hit_point);
	t_max = vec_len(subtract_vec(ray.origin, obj->l[0].coordinates));
	if (is_shadowed(obj, ray, t_max))
		return (lighting_shadow(obj, hit.color));
	phong.eye_v = normalize(subtract_vec(obj->c.coordinates, hit_point));
	phong.light_v = normalize(subtract_vec(obj->l[0].coordinates, hit_point));
	phong.normal_v = hit.normal;
	phong.reflect_v = normalize(reflect_at(scale_vec(phong.light_v, -1),
				phong.normal_v));
	return (lighting(obj, hit.color, phong));
}
