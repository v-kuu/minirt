/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:55:37 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/29 16:10:24 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	draw_screen(void *param);
static void	keybinds(void *param);

int	g_active;

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
	g_active = 1;
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
	t_sphere		sphere;
	int				x;
	int				y;
	float			hit;

	if (!g_active)
		return ;
	g_active = 0;
	sphere.radius = 1;
	sphere.center = (t_vec3){0, 0, -2};
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ray = pixel_ray(vp->cam_origin, *vp, x, y);
			hit = sphere_intersection(sphere, ray);
			if (hit >= 0)
				mlx_put_pixel(vp->img, (WIDTH - x - 1) ,y, normal_visual(ray, sphere.center, hit));
			else
				mlx_put_pixel(vp->img, x, y, background_color(ray));
		}
	}
}

static void	keybinds(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
