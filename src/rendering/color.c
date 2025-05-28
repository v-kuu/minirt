/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:28:34 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/27 20:04:48 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
/*
t_color	background_color(t_ray ray)
{
	t_vec3	unit_direction;
	float	fraction;

	unit_direction = unit_vec(ray.direction);
	fraction = 0.5 * (unit_direction.y + 1.0);
	return ((1.0 - fraction) * 0xFFFFFFFF + (fraction * 0x77BBFFFF));
}
*/

t_color	background_color(t_ray ray)
{
	t_vec3	unit_direction;
	float	fraction;
	t_color	red;
	t_color	blue;
	t_color	green;

	unit_direction = unit_vec(ray.direction);
	fraction = 0.5 * (unit_direction.y + 1.0);
	red = (0xFF - 0x77) * fraction + (0x77);
	blue = (0xFF - 0xBB) * fraction + (0xBB);
	green = (0xFF - 0xFF) * fraction + (0xFF);
	return (red << 24 | blue << 16 | green << 8 | 0xFF);
}
