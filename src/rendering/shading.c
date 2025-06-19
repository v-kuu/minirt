

#include "../../minirt.h"

t_vec3	normal_at(t_sphere sphere, t_vec3 point)
{
	return (normalize(subtract_vec(point, sphere.center)));
}

t_vec3	reflect_at(t_ray ray, t_vec3 light_n)
{
	t_vec3	in_v;
	float	dot;

	in_v = normalize(scale_vec(ray.direction, -1));
	;
	dot = dot_product(in_v, light_n);
	return (subtract_vec(in_v, scale_vec(light_n, 2 * dot)));
}

t_rgbcolor	add_colors(t_rgbcolor c1, t_rgbcolor c2)
{
	return ((t_rgbcolor){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

t_rgbcolor	multiply_color_by(t_rgbcolor c1, float value)
{
	return ((t_rgbcolor){c1.r * value, c1.g * value, c1.b * value});
}
t_rgbcolor	normalize_color(t_rgbcolor c1)
{
	return ((t_rgbcolor){c1.r / 255.0f, c1.g / 255.0f, c1.b / 255.0f});
}

t_rgbcolor	lightining(t_vec3 point, t_objects *objects, t_sphere obj,
		t_phong phong)
{
	t_rgbcolor	effective_color;
	t_rgbcolor	ambient;
	t_rgbcolor	diffuse;
	t_rgbcolor	specular;
	t_vec3		lightv;
	float		epsilon;

	(void)specular;
	effective_color = multiply_color_by(normalize_color(obj.color),	objects->l[0].b_ratio);
	lightv = normalize(subtract_vec(objects->l[0].coordinates, point));
	ambient = multiply_color_by(normalize_color(obj.color), objects->a.ratio);
	epsilon = dot_product(lightv, phong.normal_v);
	if (epsilon < 0)
	{
		diffuse = (t_rgbcolor){0, 0, 0};
		specular = (t_rgbcolor){0, 0, 0};
	}
	else
	{
		diffuse = multiply_color_by(effective_color, epsilon);
	}
	printf("diffuse is %f , %f, %f \n", diffuse.r, diffuse.g, diffuse.b);
	return (add_colors(ambient, diffuse));
}

t_rgbcolor	shading_vectors(t_objects *obj, t_ray ray, float hit, int index)
{
	t_phong	phong;
	t_vec3	hit_point;

	/*
		ambinet light color is white in the mandatory part.
		Each pixel of our scene will be multiplied by the given
			brightness ratio, aka ambient ratio.
	*/
	hit_point = ray_at(ray, hit);
	phong.eye_v = subtract_vec(obj->c.coordinates, hit_point);
	phong.light_v = subtract_vec(obj->l[0].coordinates, hit_point);
	phong.normal_v = normal_at(obj->sp[index], hit_point);
	phong.reflect_V = reflect_at(ray, phong.light_v);
	lightining(hit_point, obj, obj->sp[0], phong);
	return (lightining(hit_point, obj, obj->sp[0], phong));
	// final_color = (ambient + diffuse + specular) * sphere_color;
}
