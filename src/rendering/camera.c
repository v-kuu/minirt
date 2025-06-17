/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:32:41 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/15 20:00:16 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	calculate_pixel_zero(t_viewp *screen, float focal_length);

t_viewp	create_viewport(t_ray cam_vec, float fov_rad, int width, int height)
{
	t_viewp	screen;
	t_vec3	temp;
	float	focal_length;

	screen.cam_origin = cam_vec.origin;
	focal_length = ((float)width / 2) / (tan(fov_rad / 2));
	temp = cross_product(cam_vec.direction, (t_vec3){0, 1, 0});
	screen.horizontal = scale_vec(temp, width);
	temp = cross_product(cam_vec.direction, unit_vec(screen.horizontal));
	screen.vertical = scale_vec(temp, -height);
	screen.delta_u = divide_vec(screen.horizontal, width);
	screen.delta_v = divide_vec(screen.vertical, height);
	calculate_pixel_zero(&screen, focal_length);
	return (screen);
}

static void	calculate_pixel_zero(t_viewp *screen, float focal_length)
{
	t_vec3	upper_left;
	t_vec3	temp;

	temp = subtract_vec(screen->cam_origin, (t_vec3){0, 0, focal_length});
	temp = subtract_vec(temp, divide_vec(screen->horizontal, 2));
	upper_left = subtract_vec(temp, divide_vec(screen->vertical, 2));
	temp = scale_vec(add_vec(screen->delta_u, screen->delta_v), 0.5f);
	screen->pixel_zero = add_vec(upper_left, temp);
}
