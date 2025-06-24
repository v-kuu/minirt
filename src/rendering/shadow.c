#include "../../minirt.h"

float	ft_clamp(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_vec3	reflect_at(t_vec3 in_v, t_vec3 light_n)
{
	float	dot;

	dot = dot_product(in_v, light_n);
	return (subtract_vec(in_v, scale_vec(light_n, 2 * dot)));
}

t_rgbcolor	lightining_shadow(t_objects *obj, t_rgbcolor obj_color)
{
	t_rgbcolor	ambient;

	ambient = multiply_colors(normalize_color(obj_color),
			normalize_color(obj->a.color));
	ambient = multiply_color_by(ambient, obj->a.ratio);
	return (color_clamping(ambient));
}

bool	is_shadowed(t_objects *obj, t_hit hit)
{
	t_ray	shadow_ray;
	t_hit	sh_hit;
	float	t_max;
	int		index;
	t_vec3 shadow_origin;

	// Offset the origin to avoid self-shadowing
	shadow_origin = add_vec(ray_at(hit.ray, hit.t), scale_vec(hit.normal, 0.0001f));
	index = -1;
	shadow_ray = (t_ray){shadow_origin,
		subtract_vec(obj->l[0].coordinates, shadow_origin)};
	t_max = vec_len(shadow_ray.direction);


	shadow_ray.direction = normalize(shadow_ray.direction);
	
	while (++index < obj->spctr)
	{
		sh_hit = sphere_intersection(obj->sp[index], shadow_ray);
		if (sh_hit.t >= 0 && sh_hit.t < t_max)
			return (true);
	}
	index = -1;
	while (++index < obj->plctr)
	{
		sh_hit = plane_intersection(obj->pl[index], shadow_ray);
		if (sh_hit.t >= 0 && sh_hit.t < t_max)
			return (true);
	}
	index = -1;
	while (++index < obj->cyctr)
	{
		sh_hit = cylinder_intersection(obj->cy[index], shadow_ray);
		if (sh_hit.t >= 0 && sh_hit.t < t_max)
			return (true);
	}
	return (false);
}
