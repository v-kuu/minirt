/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:55:37 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/20 17:43:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	draw_screen(void *param);
static void render_pixel(int x, int y, t_ray ray, const t_viewp *vp);
static void	keybinds(void *param);

int	g_active;

int	rendering_loop(t_data *data)
{
	mlx_t		*mlx;
	t_viewp		screen;
	t_camera	cam;

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	if (!mlx)
		return (1);
	cam = data->objects->c;
	screen = create_viewport(cam, (cam.fov * (M_PI / 180)), WIDTH, HEIGHT);
	screen.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!screen.img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	screen.obj = data->objects;
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
	int				x;
	int				y;

	if (!g_active)
		return ;
	g_active = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ray = pixel_ray(vp->cam_origin, *vp, x, y);
			render_pixel(x, y, ray, vp);
		}
	}
}

static void render_pixel(int x, int y, t_ray ray, const t_viewp *vp)
{
	t_objects	*obj = vp->obj;
	t_hit			hit;
	t_hit			closest;
	int				index;

	index = -1;
	closest.t = FLT_MAX;
	while (++index < obj->spctr)
	{
		hit = sphere_intersection(obj->sp[index], ray);
		if (hit.t >= 0)
		{
			if (hit.t < closest.t)
			{
				closest = hit;
				// mlx_put_pixel(vp->img, x, y,
				// 		normal_visual(ray, obj->sp[index].center, hit));
				mlx_put_pixel(vp->img, x, y,
						shading_visual(shading_vectors(obj, ray, hit, index)));
			}
		}
	}
	index = -1;
	while (++index < obj->plctr)
	{
		hit = plane_intersection(obj->pl[index], ray);
		if (hit.t >= 0)
		{
			if (hit.t < closest.t)
			{
				closest = hit;
				// mlx_put_pixel(vp->img, x, y,
				// 		plane_visual(ray, obj->pl[index], hit));
				mlx_put_pixel(vp->img, x, y,
						shading_visual(pl_shading_vectors(obj, ray, hit, index)));

			}
		}
	}
	index = -1;
	while (++index < obj->cyctr)
	{
		hit = cylinder_intersection(obj->cy[index], ray);
		if (hit.t >= 0)
		{
			if (hit.t < closest.t)
			{
				closest = hit;
				mlx_put_pixel(vp->img, x, y,
						cyl_normal(ray, obj->cy[index].center, hit));
			}
		}
	}
	if (closest.t == FLT_MAX)
		mlx_put_pixel(vp->img, x, y, background_color(ray));
}

static void	keybinds(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
