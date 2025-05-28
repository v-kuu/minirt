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

#include "../minirt.h"

static void	draw_screen(void *param);
static void	keybinds(void *param);

int	rendering_loop(void)
{
	mlx_t	*mlx;
	t_refs	refs;

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	if (!mlx)
		return (1);
	refs.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!refs.img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	refs.cam = init_camera((t_vec3){0,0,0}, (t_vec3){0,0,-1}, 70);
	refs.vp = create_viewport(refs.cam, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, refs.img, 0, 0);
	mlx_loop_hook(mlx, draw_screen, &refs);
	mlx_loop_hook(mlx, keybinds, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

static void	draw_screen(void *param)
{
	const t_refs	*refs = param;
	t_ray			ray;
	int				x;
	int				y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ray = pixel_ray(cam.origin, refs->vp, x, y);
	//		printf("{%f, %f, %f} {%f, %f, %f}\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.direction.x, ray.direction.y, ray.direction.z);
			mlx_put_pixel(refs->img, x, y, background_color(ray));
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
