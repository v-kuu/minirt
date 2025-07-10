/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:28:34 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 15:04:24 by vkuusela         ###   ########.fr       */
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

	unit_direction = normalize(ray.direction);
	fraction = 0.5 * (-unit_direction.y + 1.0);
	red = (0xFF - 0x77) * fraction + (0x77);
	green = (0xFF - 0xBB) * fraction + (0xBB);
	blue = (0xFF - 0xFF) * fraction + (0xFF);
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

t_color	shading_visual(t_rgbcolor color)
{
	float	r;
	float	g;
	float	b;

	r = color.r * 255.0f;
	g = color.g * 255.0f;
	b = color.b * 255.0f;
	return (((int)r << 24) | ((int)g << 16) | ((int)b << 8) | 0xFF);
}
