/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:32:41 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/27 20:04:51 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_cam	init_camera(t_vec3 origin, t_vec3 orientation, float fov)
{
	t_cam	cam;

	cam.origin = origin;
	cam.forward = orientation;
	cam.fov_rad = fov * (M_PI / 180);
	cam.up = (t_vec3){0, 1, 0};
	return (cam);
}

t_viewport	create_viewport(t_cam cam, float width, float height)
{
	t_viewport	screen;
	t_vec3		temp;

	screen.width = width;
	screen.height = height;
	screen.aspect_ratio = (float)screen.width / screen.height;
	screen.horizontal = scale_vec(
			cross_product(cam.forward, cam.up), screen.width);
	screen.vertical = scale_vec(
			cross_product(cam.forward, screen.horizontal), screen.height);
	screen.delta_horizontal = divide_vec(screen.horizontal, screen.width);
	screen.delta_vertical = divide_vec(screen.vertical, screen.height);
	screen.focal_length = ((float)screen.width / 2) / (tan(cam.fov_rad / 2));
	temp = subtract_vec(cam.origin, (t_vec3){0, 0, screen.focal_length});
	temp = subtract_vec(temp, divide_vec(screen.horizontal, 2));
	screen.upper_left = subtract_vec(temp, divide_vec(screen.vertical, 2));
	temp = add_vec(screen.delta_horizontal, screen.delta_vertical);
	temp = scale_vec(temp, 0.5f);
	screen.pixel_zero = add_vec(screen.upper_left, temp);
	return (screen);
}
