

#include "../../minirt.h"

t_vec3	sp_normal_at(t_sphere sphere, t_vec3 point)
{
	return (normalize(subtract_vec(point, sphere.center)));
}

void color_climping(t_lights *light)
{
	light->final.r = ft_clamp(light->final.r, 0.0f, 1.0f);
	light->final.g = ft_clamp(light->final.g, 0.0f, 1.0f);
	light->final.b = ft_clamp(light->final.b, 0.0f, 1.0f);
}
void light_calculation(t_lights *light, t_phong *phong, t_light *light_obj)
{
if (light->epsilon < 0)
	{
		light->diffuse = (t_rgbcolor){0, 0, 0};
		light->specular = (t_rgbcolor){0, 0, 0};
	}
	else
	{
		light->diffuse = multiply_color_by(light->effective_color, light->epsilon);
		light->epsilon = 0;
		light->epsilon = dot_product(phong->reflect_V, phong->eye_v);
		if (light->epsilon > 0)
		{
			light->factor = powf(light->epsilon, SHININESS);
			light->specular = multiply_color_by(normalize_color(light_obj->color),
					light->factor * light_obj->b_ratio * SPECULAR);
		}
		else
			light->specular = (t_rgbcolor){0, 0, 0};
	}
}

t_rgbcolor	lightining(t_a_light a_light,t_light l_light, t_rgbcolor obj_color, t_phong phong, bool in_shadows)
{
	t_lights light;

	light.effective_color = multiply_color_by(normalize_color(obj_color),
			l_light.b_ratio);
	light.ambient = multiply_color_by(normalize_color(obj_color), a_light.ratio);
	light.epsilon = dot_product(phong.light_v, phong.normal_v);
	light_calculation(&light, &phong, &l_light);
	if (in_shadows)
		light.final = light.ambient;
	else
		light.final = add_colors(add_colors(light.ambient, light.diffuse), light.specular);
	color_climping(&light);
	return (light.final);
}

t_rgbcolor	shading_vectors(t_objects *obj, t_rgbcolor obj_color,  t_hit hit)
{
	t_phong	phong;
	t_vec3	hit_point;
	bool in_shadows = false;
	hit_point = ray_at(hit.ray, hit.t);
	phong.eye_v = normalize(subtract_vec(obj->c.coordinates, hit_point));
	phong.light_v = normalize(subtract_vec(obj->l[0].coordinates, hit_point));
	phong.normal_v = hit.normal;
	phong.reflect_V = normalize(reflect_at(scale_vec(phong.light_v, -1),
				phong.normal_v));
	return (lightining(obj->a,obj->l[0], obj_color, phong, in_shadows));
}