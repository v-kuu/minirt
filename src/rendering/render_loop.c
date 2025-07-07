/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:15:42 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 15:38:01 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	draw_screen(void *param);
static void	render_pixel(int x, int y, t_ray ray, const t_viewp *vp);
static void	find_closest(t_objects *obj, t_ray ray, t_hit *closest);
static void	keybinds(void *param);

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
	screen.active = 1;
	calculate_cylinder_quats(screen.obj);
	mlx_image_to_window(mlx, screen.img, 0, 0);
	mlx_loop_hook(mlx, draw_screen, &screen);
	mlx_loop_hook(mlx, keybinds, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

static void	draw_screen(void *param)
{
	t_viewp	*vp;
	t_ray	ray;
	int		x;
	int		y;

	vp = param;
	if (!vp->active)
		return ;
	vp->active = 0;
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

static void	render_pixel(int x, int y, t_ray ray, const t_viewp *vp)
{
	t_hit		closest;

	closest.t = FLT_MAX;
	find_closest(vp->obj, ray, &closest);
	if (closest.t == FLT_MAX)
		mlx_put_pixel(vp->img, x, y, background_color(ray));
	else
	{
		closest.ray = ray;
		mlx_put_pixel(vp->img, x, y,
			shading_visual(shading_vectors(vp->obj, closest)));
	}
}

static void	find_closest(t_objects *obj, t_ray ray, t_hit *closest)
{
	int		index;
	t_hit	hit;

	index = -1;
	while (++index < obj->spctr)
	{
		hit = sphere_intersection(obj->sp[index], ray);
		if (hit.t >= 0 && hit.t < closest->t)
			*closest = hit;
	}
	index = -1;
	while (++index < obj->plctr)
	{
		hit = plane_intersection(obj->pl[index], ray);
		if (hit.t >= 0 && hit.t < closest->t)
			*closest = hit;
	}
	index = -1;
	while (++index < obj->cyctr)
	{
		hit = cylinder_intersection(obj->cy[index], ray);
		if (hit.t >= 0 && hit.t < closest->t)
			*closest = hit;
	}
}

static void	keybinds(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
