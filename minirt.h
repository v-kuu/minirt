/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:04:01 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 16:08:48 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define MAX_LINES 200
# define MOL 1000.0f // max coordinates value
# define WIDTH 1920
# define HEIGHT 1080
# define SHININESS 10  // in lighting
# define SPECULAR 0.2f // in lighting
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef uint32_t	t_color;

typedef struct s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_quaternion
{
	float			w;
	float			x;
	float			y;
	float			z;
}					t_quaternion;

typedef struct s_rgbcolor
{
	float			r;
	float			g;
	float			b;
}					t_rgbcolor;

typedef struct s_hit_record
{
	float			t;
	t_vec3			normal;
	t_rgbcolor		color;
	t_ray			ray;
}					t_hit;

typedef t_vec3		t_point;

typedef struct s_light
{
	t_vec3			coordinates;
	float			b_ratio;
	t_rgbcolor		color;
}					t_light;

typedef struct s_camera
{
	t_vec3			coordinates;
	t_vec3			orientations;
	float			fov;
}					t_camera;

typedef struct s_a_light
{
	float			ratio;
	t_rgbcolor		color;
}					t_a_light;

typedef struct s_sphere
{
	t_vec3			center;
	float			radius;
	t_rgbcolor		color;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_rgbcolor		color;
}					t_plane;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axis;
	t_quaternion	q_axis;
	float			diameter;
	float			height;
	t_rgbcolor		color;
}					t_cylinder;

typedef struct s_objects
{
	t_a_light		a;
	t_camera		c;
	t_light			*l;
	t_plane			*pl;
	t_sphere		*sp;
	t_cylinder		*cy;
	int				lctr;
	int				plctr;
	int				spctr;
	int				cyctr;
}					t_objects;

typedef struct s_s_lines
{
	char			**line;
}					t_s_lines;

typedef struct s_data
{
	char			**read_lines;
	t_s_lines		*lines;
	t_objects		*objects;
	int				lines_counter;
	int				light_counter;
	int				sp_counter;
	int				cy_counter;
	int				pl_counter;
	int				px_counter;
	int				cp_counter;
}					t_data;

typedef struct s_phong_vectors
{
	t_vec3			eye_v;
	t_vec3			light_v;
	t_vec3			normal_v;
	t_vec3			reflect_v;
}					t_phong;

typedef struct s_lights
{
	t_rgbcolor		effective_color;
	t_rgbcolor		ambient;
	t_rgbcolor		diffuse;
	t_rgbcolor		specular;
	float			epsilon;
	float			factor;
	t_rgbcolor		final;
}					t_lights;

typedef struct s_cam
{
	t_vec3			origin;
	t_vec3			forward;
	t_vec3			up;
	float			fov_rad;
}					t_cam;

typedef struct s_viewp
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_objects		*obj;
	int				width;
	int				height;
	float			fov_rad;
	int				active;
	t_vec3			cam_origin;
	t_vec3			cam_dir;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			delta_u;
	t_vec3			delta_v;
	t_vec3			upper_left;
	t_vec3			pixel_zero;
}					t_viewp;

void				open_file_read(char **argv, t_data *data);
void				check_filename(char **argv);
void				check_arguments(int argc, char **argv);
void				print_error_exit(void);
bool				parsing(t_data *data);
int					arr_count(char **arr);
void				free_lines_arr(t_s_lines *objects);
void				free_objects(t_data *data);
bool				validation(t_data *data);
bool				validate_a(t_a_light a);
float				ft_atof(char *str);
void				exit_free_parsing(t_data *data);
bool				color_validation(t_rgbcolor *color);
void				case_a(t_data *data, t_objects *objects, int i);
void				case_c(t_data *data, t_objects *objects, int i);
void				case_l(t_data *data, t_objects *objects, int i);
void				case_sp(t_data *data, t_objects *objects, int i);
void				case_pl(t_data *data, t_objects *objects, int i);
void				case_cy(t_data *data, t_objects *objects, int i);
bool				fill_in_coordinates(t_data *data, int i, t_vec3 *coords);
bool				fill_in_orientations(t_data *data, int i, t_vec3 *orinets);
bool				fill_in_c_fov(t_data *data, int i, t_camera *c);
bool				fill_in_rgb(char *value, t_rgbcolor *color);
bool				malloc_all_objects(t_data *data);
bool				fill_in_value(char *value, float *src);
void				remove_white_spaces(char *line);
bool				color_validation(t_rgbcolor *color);
void				open_file_read(char **argv, t_data *data);
void				check_filename(char **argv);
void				check_arguments(int argc, char **argv);
int					not_empty_lines(t_data *data);
void				print_error_exit(void);

////////////////////////////////////////////////////////////// render_loop.c //

/*
 *	Sets up mlx and starts the rendering
 */
int					rendering(t_data *data);

//////////////////////////////////////////////////////// vector_operations.c //

/*
 * Add two vectors together to form a new vector
 */
t_vec3				add_vec(const t_vec3 first, const t_vec3 second);

/*
 * Subtract the second vector from the first, forming a new vector
 */
t_vec3				subtract_vec(const t_vec3 first, const t_vec3 second);

/*
 * Multiply the scalar parts of two vectors, returning the resulting vector
 */
t_vec3				multiply_vec(const t_vec3 first, const t_vec3 second);

/*
 * Scale a vector by multiplying the components with a scalar (multiply)
 */
t_vec3				scale_vec(const t_vec3 vector, float scalar);

/*
 * Divide a vector by scalar
 */
t_vec3				divide_vec(const t_vec3 vector, float scalar);

////////////////////////////////////////////////////////// vector_products.c //

/*
 * Calculates the dot product between 2 vectors. The dot product tells us
 * information abot the angle between the vectors.
 * A return value of > 0 means the angle is less than 90°, 0 means it is exactly
 * 90°, and a value of < 0 means the angle is more than 90°, for example.
 */
float				dot_product(const t_vec3 first, const t_vec3 second);

/*
 * Given 2 vectors, the cross product can be seen as the normal of the plane
 * containing the two vectors. For example, the cross product of (1, 0, 0) and
 * (0, 1, 0) is equal to (0, 0, 1)
 */
t_vec3				cross_product(const t_vec3 first, const t_vec3 second);

//////////////////////////////////////////////////////// vector_properties.c //

/*
 * Returns the length of the given vector
 */
float				vec_len(const t_vec3 vector);

/*
 * Returns the vector scaled to length 1
 */
t_vec3				normalize(const t_vec3 vector);

/////////////////////////////////////////////////////////////// quaternion.c //

/*
 * Returns a quaternion representing the rotation from one vector to another
 */
t_quaternion		create_rotation_quat(t_vec3 from, t_vec3 to);

/*
 * Rotates a vector by a quaternion
 */
t_vec3				rotate_by_quat(t_quaternion quat, t_vec3 vec);

/*
 * Normalizes a quaternion
 */
t_quaternion		normalize_quat(t_quaternion quat);

/*
 * Inverts a quaternion
 */
t_quaternion		inverse_quat(t_quaternion quat);

//////////////////////////////////////////////////////////////////// color.c //

/*
 * Returns the default background color for the current ray
 */
t_color				background_color(t_ray ray);

/*
 * Returns a color based on the normal
 */
t_color				shading_visual(t_rgbcolor color);

t_vec3				sp_normal_at(t_sphere sphere, t_vec3 point);

/////////////////////////////////////////////////////////////////// camera.c //

/*
 * Calculate the viewport based on camera data and screen dimensions
 */
t_viewp				create_viewport(t_camera cam, float fov_rad, int width,
						int height);

/*
 * Recalculate viewport when screen gets resized
 */
void				resize_screen(int32_t width, int32_t height, void *param);

////////////////////////////////////////////////////////////////////// ray.c //

/*
 * Calculates the current ray vectors for the current pixel on screen
 */
t_ray				pixel_ray(t_vec3 origin, t_viewp viewport, int x, int y);

/*
 * Calculates the ray from an intersection to light source
 */
t_ray				light_ray(t_hit hit, t_light light, t_point hit_point);

/*
 * Returns the location where the ray hit
 */
t_point				ray_at(t_ray ray, float hit);

/*
 * Converts a local t into world t
 */
float				t_from_point(t_point hit, t_ray ray);

/*
 * Rotates a ray by a given quat
 */
t_ray				rotate_ray(t_ray ray, t_quaternion quat);

//////////////////////////////////////////////////////////// hit_detection.c //

/*
 * Calculates if a given ray intersects a sphere
 */
t_hit				sphere_intersection(t_sphere sphere, t_ray ray);

/*
 * Calculates if a given ray intersects a plane
 */
t_hit				plane_intersection(t_plane plane, t_ray ray);

/////////////////////////////////////////////////////// cylinder_detection.c //

/*
 * Calculates if a given ray intersects a cylinder
 */
t_hit				cylinder_intersection(t_cylinder cyl, t_ray ray);

/*
 * Calculate quaternions for cylinder axis
 */
void				calculate_cylinder_quats(t_objects *obj);

t_color				light_visual(t_objects obj, t_ray ray, float hit,
						int index);
/*
 * Calculates the final color after lighting and shadow.
 */						
t_rgbcolor			shading_vectors(t_objects *obj, t_hit hit);

/*
 * return the min or the max if the value exceed the min and max.
 */
float				ft_clamp(float val, float min, float max);

/*
 * return the reflected vector.
 */
t_vec3				reflect_at(t_vec3 in_v, t_vec3 light_n);

/*
 * return the new color came from 2 colors. color1 + color2
 */
t_rgbcolor			add_colors(t_rgbcolor c1, t_rgbcolor c2);

/*
 * return the new color came after scale it with a value.
 */
t_rgbcolor			multiply_color_by(t_rgbcolor c1, float value);

/*
 * return the normal value of the color. from 0-1
 */
t_rgbcolor			normalize_color(t_rgbcolor c1);
/*
 * return the new color came after multiplying  colors
 */
t_rgbcolor			multiply_colors(t_rgbcolor c1, t_rgbcolor c2);

/*
 * return the new color came after calculating the effect of lights and shadows
 */
t_rgbcolor			lighting_shadow(t_objects *obj, t_rgbcolor obj_color);

/*
 * return the status of the hit point if it in shadow or or
 */
bool				is_shadowed(t_objects *obj, t_ray ray, float t_max);

/*
 * return the new color after clamping and make it max to 255,
 * and the min is 0. it will protect from overflows.
 */
t_rgbcolor			color_clamping(t_rgbcolor color);

#endif
