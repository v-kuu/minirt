/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:32:41 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:47:09 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	calculate_pixel_zero(t_viewp *screen, float focal_length);

t_viewp	create_viewport(t_camera cam, float fov_rad, int width, int height)
{
	t_viewp	screen;
	t_vec3	temp;
	float	focal_length;

	screen.width = width;
	screen.height = height;
	screen.cam_origin = cam.coordinates;
	screen.cam_dir = cam.orientations;
	screen.fov_rad = fov_rad;
	focal_length = ((float)width / 2) / (tan(fov_rad / 2));
	temp = cross_product(screen.cam_dir, (t_vec3){0, 1, 0});
	if (dot_product(temp, temp) == 0)
		temp = (t_vec3){1, 0, 0};
	screen.horizontal = scale_vec(temp, width);
	temp = cross_product(screen.cam_dir, normalize(screen.horizontal));
	screen.vertical = scale_vec(temp, height);
	screen.delta_u = divide_vec(screen.horizontal, width);
	screen.delta_v = divide_vec(screen.vertical, height);
	calculate_pixel_zero(&screen, focal_length);
	screen.active = 1;
	return (screen);
}

static void	calculate_pixel_zero(t_viewp *screen, float focal_length)
{
	t_vec3	vp_center;
	t_vec3	upper_left;
	t_vec3	temp;

	temp = scale_vec(screen->cam_dir, focal_length);
	vp_center = add_vec(screen->cam_origin, temp);
	temp = subtract_vec(vp_center, divide_vec(screen->horizontal, 2));
	upper_left = subtract_vec(temp, divide_vec(screen->vertical, 2));
	temp = scale_vec(add_vec(screen->delta_u, screen->delta_v), 0.5f);
	screen->pixel_zero = add_vec(upper_left, temp);
}

void	resize_screen(int32_t width, int32_t height, void *param)
{
	t_viewp	*screen;
	t_vec3	temp;
	float	focal_length;

	screen = param;
	screen->width = width;
	screen->height = height;
	focal_length = ((float)screen->width / 2) / (tan(screen->fov_rad / 2));
	temp = cross_product(screen->cam_dir, (t_vec3){0, 1, 0});
	if (dot_product(temp, temp) == 0)
		temp = (t_vec3){1, 0, 0};
	screen->horizontal = scale_vec(temp, screen->width);
	temp = cross_product(screen->cam_dir, normalize(screen->horizontal));
	screen->vertical = scale_vec(temp, screen->height);
	screen->delta_u = divide_vec(screen->horizontal, screen->width);
	screen->delta_v = divide_vec(screen->vertical, screen->height);
	calculate_pixel_zero(screen, focal_length);
	mlx_resize_image(screen->img, screen->width, screen->height);
	screen->active = 1;
}
