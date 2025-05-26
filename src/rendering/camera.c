/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:04:22 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 19:29:14 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"
//fixpls
t_cam	init_cam(void)
{
	t_cam	cam;

	cam.focal_length = 1.0;
	cam.viewport_height = 2.0;
	cam.viewport_width = cam.viewport_height * ((float)WIDTH / HEIGHT);
	cam.center = (t_vec3){0, 0, 0};
	cam.viewport_horizontal = (t_vec3){cam.viewport_width, 0, 0};
	cam.viewport_vertical = (t_vec3){0, -cam.viewport_height, 0};
	cam.horizontal_delta = divide_vec(cam.viewport_horizontal, WIDTH);
	cam.vertical_delta = divide_vec(cam.viewport_vertical, HEIGHT);
	cam.viewport_zero =;
}

