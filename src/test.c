#include "../minirt.h"

static void	draw_screen(void *param);
static void	keybinds(void *param);

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, draw_screen, img);
	mlx_loop_hook(mlx, keybinds, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

static void	draw_screen(void *param)
{
	mlx_image_t	*img;
	t_ray		ray;
	int			x;
	int			y;

	img = param;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img, x, y, background_color(ray));
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
