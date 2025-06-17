#ifndef MINIRT_H
# define MINIRT_H

# define MAX_LINES 200
# define MOL 1000.0f // max coordinates value
# define WIDTH 1920
# define HEIGHT 1080

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

typedef t_vec3	t_point;

typedef struct s_rgbcolor
{
	float			r;
	float			g;
	float			b;
}					t_rgbcolor;

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

	int lctr; /// added_lights_counter
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

void				open_file_read(char **argv, t_data *data);
void				check_filename(char **argv);
void				check_arguments(int argc, char **argv);
void				print_error_exit(void);
void				free_2d_arr(char **arr);
bool				parsing(t_data *data);
void				print_lines(t_data *data);
void				free_lines_arr(t_s_lines *objects);
bool				validation(t_data *data);
int					ft_strcmp(const char *s1, const char *s2);
bool				validate_a(t_a_light a);
float				ft_atof(char *str);
void				exit_free_parsing(t_data *data);
bool				color_validation(t_rgbcolor *color);
void				case_a(t_data *data, t_objects *objects, int i);
void				case_c(t_data *data, t_objects *objects, int i);
void				case_l(t_data *data, t_objects *objects, int i);
void				case_sp(t_data *data, t_objects *objects, int i);
void				case_pl(t_data *data, t_objects *objects, int i);
void	case_cy(t_data *data, t_objects *objects, int i);

void	print_camera(t_data *data); // must be removed
bool				fill_in_coordinates(t_data *data, int i, t_vec3 *coords);
bool				fill_in_orientations(t_data *data, int i, t_vec3 *orinets);
bool				fill_in_RGB(char *value, t_rgbcolor *color);
bool				malloc_all_objects(t_data *data);
bool	fill_in_value(char *value, float *src);

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_cam
{
	t_vec3			origin;
	t_vec3			forward;
	t_vec3			up;
	float			fov_rad;
}					t_cam;

typedef struct s_viewp
{
	mlx_image_t		*img;
	t_objects		*obj;
	t_vec3			cam_origin;
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
void				free_2d_arr(char **arr);

////////////////////////////////////////////////////////////// render_loop.c //

/*
 *	Sets up mlx and starts the rendering
 */
int					rendering_loop(t_data *data);

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
t_vec3				unit_vec(const t_vec3 vector);

//////////////////////////////////////////////////////////////////// color.c //

/*
 * Returns the default background color for the current ray
 */
t_color				background_color(t_ray ray);

/*
 * Returns a color based on the normal
 */
t_color	normal_visual(t_ray ray, t_vec3 center, float hit);
t_color	plane_visual(t_ray ray, t_plane plane, float hit);

/////////////////////////////////////////////////////////////////// camera.c //

/*
 * Initialize the basic camera object
 */
t_cam				init_camera(t_vec3 origin, t_vec3 orientation, float fov);

/*
 * Calculate the viewport based on camera data and screen dimensions
 */
t_viewp				create_viewport(t_ray cam_vec, float fov_rad, int width,
						int height);

////////////////////////////////////////////////////////////////////// ray.c //

/*
 * Calculates the current ray vectors for the current pixel on screen
 */
t_ray				pixel_ray(t_vec3 origin, t_viewp viewport, int x, int y);

/*
 * Returns the location where the ray hit
 */
t_point	ray_at(t_ray ray, float hit);

//////////////////////////////////////////////////////////// hit_detection.c //

/*
 * Calculates if a given ray intersects a sphere
 */
float	sphere_intersection(t_sphere sphere, t_ray ray);
float plane_intersection(t_plane plane, t_ray ray);

#endif
