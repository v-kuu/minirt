/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:42:43 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:50 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray	pixel_ray(t_vec3 origin, t_viewport viewport, int x, int y)
{
	t_vec3	ray_direction;
	t_vec3	pixel_center;
	t_vec3	temp;

	viewport.delta_horizontal = scale_vec(viewport.delta_horizontal, x);
	viewport.delta_vertical = scale_vec(viewport.delta_vertical, y);
	temp = add_vec(viewport.delta_horizontal, viewport.delta_vertical);
	pixel_center = add_vec(viewport.pixel_zero, temp);
	ray_direction = subtract_vec(pixel_center, origin);
	return ((t_ray){origin, ray_direction});
}
