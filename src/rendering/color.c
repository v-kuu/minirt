/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:28:34 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/29 16:17:44 by vkuusela         ###   ########.fr       */
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
	fraction = 0.5 * (unit_direction.y + 1.0);
	red = (0xFF - 0x77) * fraction + (0x77);
	green = (0xFF - 0xBB) * fraction + (0xBB);
	blue = (0xFF - 0xFF) * fraction + (0xFF);
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

t_color	normal_visual(t_ray ray, t_vec3 center, float hit)
{
	t_vec3	unit_normal;
	float	fraction;
	t_color	red;
	t_color	green;
	t_color	blue;

	unit_normal = unit_vec(subtract_vec(ray_at(ray, hit), center));
	fraction = 0.5 * (unit_normal.x + 1.0);
	red = (0x00 - 0xFF) * fraction + (0xFF);
	red <<= 24;
	fraction = 0.5 * (unit_normal.y + 1.0);
	green = (0x00 - 0xFF) * fraction + (0xFF);
	green <<= 16;
	fraction = 0.5 * (-unit_normal.z + 1.0);
	blue = (0x00 - 0xFF) * fraction + (0xFF);
	blue <<= 8;
	return (red | green | blue | 0xFF);
}
