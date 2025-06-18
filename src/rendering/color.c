/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:28:34 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/18 15:08:29 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_color	background_color(t_ray ray)
{
	t_vec3	unit_direction;
	float	fraction;
	t_color	red;
	t_color	green;
	t_color	blue;

	unit_direction = unit_vec(ray.direction);
	fraction = 0.5 * (-unit_direction.y + 1.0);
	red = (0xFF - 0x77) * fraction + (0x77);
	green = (0xFF - 0xBB) * fraction + (0xBB);
	blue = (0xFF - 0xFF) * fraction + (0xFF);
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

t_color	normal_visual(t_ray ray, t_vec3 center, t_hit hit)
{
	t_vec3	unit_normal;
	float	fraction;
	t_color	red;
	t_color	green;
	t_color	blue;

	unit_normal = unit_vec(subtract_vec(ray_at(ray, hit.t), center));
	fraction = 0.5 * (unit_normal.x + 1.0);
	red = 0xFF * fraction;
	red <<= 24;
	fraction = 0.5 * (unit_normal.y + 1.0);
	green = 0xFF * fraction;
	green <<= 16;
	fraction = 0.5 * (unit_normal.z + 1.0);
	blue = 0xFF * fraction;
	blue <<= 8;
	return (red | green | blue | 0xFF);
}

t_color	cyl_normal(t_ray ray, t_vec3 center, t_hit hit)
{
	t_vec3	unit_normal;
	float	fraction;
	t_color	red;
	t_color	green;
	t_color	blue;

	unit_normal = unit_vec(subtract_vec(ray_at(ray, hit.t), center));
	fraction = 0.5 * (unit_normal.x + 1.0);
	red = 0xFF * fraction;
	red <<= 24;
	green = 0;
	green <<= 16;
	fraction = 0.5 * (unit_normal.z + 1.0);
	blue = 0xFF * fraction;
	blue <<= 8;
	return (red | green | blue | 0xFF);
}

t_color plane_visual(t_ray ray, t_plane plane, t_hit hit)
{
	(void)hit;
	(void)ray;
	return ((0xFF << 24) | ((int)plane.color.r << 16) | ((int)plane.color.g << 8) | (int)plane.color.b);
}
