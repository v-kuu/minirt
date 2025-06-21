
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
