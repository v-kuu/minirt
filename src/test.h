#ifndef TEST_H
# define TEST_H

# define WIDTH 1920
# define HEIGHT 1080

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef uint32_t t_color;

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
	t_vec3	center;
	float	fov;
	float	focal_length;
	float	viewport_width;
	float	viewport_height;
	t_vec3	viewport_horizontal;
	t_vec3	viewport_vertical;
	t_vec3	horizontal_delta;
	t_vec3	vertical_delta;
	t_vec3	viewport_zero;
}			t_cam;

//////////////////////////////////////////////////////// vector_operations.c //

/*
 * Add two vectors together to form a new vector
 */
t_vec3	add_vec(const t_vec3 first, const t_vec3 second);

/*
 * Subtract the second vector from the first, forming a new vector
 */
t_vec3	subtract_vec(const t_vec3 first, const t_vec3 second);

/*
 * Multiply the scalar parts of two vectors, returning the resulting vector
 */
t_vec3	multiply_vec(const t_vec3 first, const t_vec3 second);

/*
 * Scale a vector by multiplying the components with a scalar (multiply)
 */
t_vec3	scale_vec(const t_vec3 vector, float scalar);

/*
 * Divide a vector by scalar
 */
t_vec3	divide_vec(const t_vec3 vector, float scalar);

////////////////////////////////////////////////////////// vector_products.c //

/*
 * Calculates the dot product between 2 vectors. The dot product tells us
 * information abot the angle between the vectors.
 * A return value of > 0 means the angle is less than 90°, 0 means it is exactly
 * 90°, and a value of < 0 means the angle is more than 90°, for example.
 */
float	dot_product(const t_vec3 first, const t_vec3 second);

/*
 * Given 2 vectors, the cross product can be seen as the normal of the plane
 * containing the two vectors. For example, the cross product of (1, 0, 0) and
 * (0, 1, 0) is equal to (0, 0, 1)
 */
t_vec3	cross_product(const t_vec3 first, const t_vec3 second);

//////////////////////////////////////////////////////// vector_properties.c //

/*
 * Returns the length of the given vector
 */
float	vec_len(const t_vec3 vector);

/*
 * Returns the unit vector of a given vector (scaled to length 1)
 */
t_vec3	unit_vec(const t_vec3 vector);

//////////////////////////////////////////////////////////////////// color.c //

/*
 * Returns the default background color for the current ray
 */
t_color background_color(t_ray ray);

#endif
