/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:55:37 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/28 19:10:04 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	draw_screen(void *param);
static void	keybinds(void *param);

int	rendering_loop(t_data *data)
{
	mlx_t		*mlx;
	t_viewp		screen;
	t_camera	cam;
	t_ray		cam_vec;

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	if (!mlx)
		return (1);
	cam = data->objects->c;
	cam_vec = (t_ray){cam.coordinates, cam.orientations};
	screen = create_viewport(cam_vec, (cam.fov * (M_PI / 180)), WIDTH, HEIGHT);
	screen.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!screen.img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	mlx_image_to_window(mlx, screen.img, 0, 0);
	mlx_loop_hook(mlx, draw_screen, &screen);
	mlx_loop_hook(mlx, keybinds, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

static void	draw_screen(void *param)
{
	const t_viewp	*vp = param;
	t_ray			ray;
	int				x;
	int				y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ray = pixel_ray(vp->cam_origin, *vp, x, y);
	//		printf("{%f, %f, %f} {%f, %f, %f}\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.direction.x, ray.direction.y, ray.direction.z);
			mlx_put_pixel(vp->img, x, y, background_color(ray));
		}
	//	printf("{%f, %f, %f} {%f, %f, %f}\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.direction.x, ray.direction.y, ray.direction.z);
	}
}

static void	keybinds(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
