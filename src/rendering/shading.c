

#include "../../minirt.h"


t_vec3	normal_at(t_sphere sphere, t_vec3 point)
{
	return (normalize(subtract_vec(point, sphere.center)));
}

t_vec3	reflect_at(t_ray ray, t_vec3 light_n)
{
	t_vec3	in_v;
	float	dot;

	in_v = normalize(scale_vec(ray.direction, -1));;
	dot = dot_product(in_v, light_n);
	return (subtract_vec(in_v, scale_vec(light_n, 2 * dot)));
}

t_color	shading_vectors(t_objects obj, t_ray ray, float hit, int index)
{
	/*
		ambinet light color is white in the mandatory part.
		Each pixel of our scene will be multiplied by the given
			brightness ratio, aka ambient ratio. 
		
	
	
	
	*/
	t_phong phong;
	t_vec3 hit_point;
	
	hit_point = ray_at(ray, hit);
	phong_init();
	phong.eye_v = subtract_vec(obj.c.coordinates, hit_point);
	phong.light_v = subtract_vec(obj.l[0].coordinates, hit_point);
	phong.normal_v = normal_at(obj.sp[index], hit_point);
	phong.reflect_V = reflect_at(ray, phong.light_v);
	lightining(hit_point,obj,phong);

	return (0xFF);
	//final_color = (ambient + diffuse + specular) * sphere_color;
}
