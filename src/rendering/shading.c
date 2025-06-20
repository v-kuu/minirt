

#include "../../minirt.h"

float	ft_clamp(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_vec3	normal_at(t_sphere sphere, t_vec3 point)
{
	return (normalize(subtract_vec(point, sphere.center)));
}

t_vec3	reflect_at(t_vec3 in_v, t_vec3 light_n)
{
	float	dot;

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

t_rgbcolor	lightining(t_objects *objects, t_sphere obj, t_phong phong)
{
	t_rgbcolor	effective_color;
	t_rgbcolor	ambient;
	t_rgbcolor	diffuse;
	t_rgbcolor	specular;
	float		epsilon;
	float		factor;
	t_rgbcolor	final;

	effective_color = multiply_color_by(normalize_color(obj.color),
			objects->l[0].b_ratio);
	ambient = multiply_color_by(normalize_color(obj.color), objects->a.ratio);
	epsilon = dot_product(phong.light_v, phong.normal_v);
	if (epsilon < 0)
	{
		diffuse = (t_rgbcolor){0, 0, 0};
		specular = (t_rgbcolor){0, 0, 0};
	}
	else
	{
		diffuse = multiply_color_by(effective_color, epsilon);
		epsilon = 0;
		epsilon = dot_product(phong.reflect_V, phong.eye_v);
		if (epsilon > 0)
		{
			factor = powf(epsilon, SHININESS);
			specular = multiply_color_by(normalize_color(objects->l[0].color),
					factor * objects->l[0].b_ratio * SPECULAR);
		}
		else
			specular = (t_rgbcolor){0, 0, 0};
	}
	final = add_colors(add_colors(ambient, diffuse), specular);
	final.r = ft_clamp(final.r, 0.0f, 1.0f);
	final.g = ft_clamp(final.g, 0.0f, 1.0f);
	final.b = ft_clamp(final.b, 0.0f, 1.0f);
	return (final);
}

t_rgbcolor	shading_vectors(t_objects *obj, t_ray ray, float hit, int index)
{
	t_phong	phong;
	t_vec3	hit_point;

	hit_point = ray_at(ray, hit);
	phong.eye_v = normalize(subtract_vec(obj->c.coordinates, hit_point));
	phong.light_v = normalize(subtract_vec(obj->l[0].coordinates, hit_point));
	phong.normal_v = normal_at(obj->sp[index], hit_point);
	phong.reflect_V = normalize(reflect_at(scale_vec(phong.light_v, -1),
				phong.normal_v));
	return (lightining(obj, obj->sp[index], phong));
}
