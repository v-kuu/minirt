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

int	rendering(t_data *data)
{
	t_viewp		screen;
	t_camera	cam;

	ft_bzero(&screen, sizeof(screen));
	cam = data->objects->c;
	screen = create_viewport(cam, (cam.fov * (M_PI / 180)), 1920, 1080);
	screen.mlx = mlx_init(1920, 1080, "minirt", true);
	if (!screen.mlx)
		return (1);
	mlx_set_window_limit(screen.mlx, 640, 640, 1920, 1080);
	screen.img = mlx_new_image(screen.mlx, 1920, 1080);
	if (!screen.img)
	{
		mlx_terminate(screen.mlx);
		return (1);
	}
	screen.obj = data->objects;
	calculate_cylinder_quats(screen.obj);
	mlx_image_to_window(screen.mlx, screen.img, 0, 0);
	mlx_resize_hook(screen.mlx, resize_screen, &screen);
	mlx_loop_hook(screen.mlx, draw_screen, &screen);
	mlx_loop_hook(screen.mlx, keybinds, screen.mlx);
	mlx_loop(screen.mlx);
	mlx_terminate(screen.mlx);
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
	while (++y < vp->height)
	{
		x = -1;
		while (++x < vp->width)
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
		if (dot_product(ray.direction, closest.normal) > 0)
			closest.normal = scale_vec(closest.normal, -1);
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
