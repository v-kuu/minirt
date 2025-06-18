

#include "../../minirt.h"


t_vec3	normal_at(t_sphere sphere, t_vec3 point)
{
	return (unit_vec(subtract_vec(point, sphere.center)));
}

t_vec3	reflect_at(t_ray ray, t_vec3 light_n)
{
	t_vec3	in_v;
	float	dot;

	in_v = unit_vec(scale_vec(ray.direction, -1));;
	dot = dot_product(in_v, light_n);
	return (subtract_vec(in_v, scale_vec(light_n, 2 * dot)));
}
t_color	shading_vectors(t_objects obj, t_ray ray, float hit, int index)
{

	t_vec3 hit_point = ray_at(ray, hit);
	t_vec3 light_e;
	t_vec3 light_l;
	t_vec3 light_n;
	t_vec3 light_r;

	light_e = subtract_vec(obj.c.coordinates, hit_point);
	light_l = subtract_vec(obj.l[0].coordinates, hit_point);
	light_n = normal_at(obj.sp[index], hit_point);
	light_r = reflect_at(ray, light_n);
	printf("test values %f%f%f", light_l.x, light_r.x, light_e.x );
	return (0xFF);
}
