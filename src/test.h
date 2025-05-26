#ifndef TEST_H
# define TEST_H

# define WIDTH 1920
# define HEIGHT 1080

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}			t_vec3;

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}			t_ray;

typedef struct	s_cam
{
	t_vec3	origin;
	t_vec3	orientation;
	float	fov;
	float	viewport_width;
	float	viewport_height;
}			t_cam;

#endif
