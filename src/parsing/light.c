#include "../../minirt.h"

bool	fill_in_b_ration(char *value, t_light *light)
{
	light->b_ratio = ft_atof(value);
	if (isnan(light->b_ratio))
		return (false);
	if (!(light->b_ratio >= 0.0 && light->b_ratio <= 1.0))
		return (false);
	return (true);
}

bool	fill_in_RGB(char *value, t_rgbcolor *color)
{
	char **rgb;
	rgb = ft_split(value, ',');
	if (!rgb)
		return (false);
	color->r = ft_atof(rgb[0]);
	color->g = ft_atof(rgb[1]);
	color->b = ft_atof(rgb[2]);
	free_2d_arr(rgb);
	if (isnan(color->r) || isnan(color->g) || isnan(color->b))
		return (false);
	if(!color_validation(color))
		return (false);
	return (true);
}

void	case_l(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->l[objects->lctr].coordinates))
		exit_free_parsing(data);
	if (!fill_in_b_ration(data->lines[i].line[2], &objects->l[objects->lctr]))
		exit_free_parsing(data);
	if (!fill_in_RGB(data->lines[i].line[3], &objects->l[objects->lctr].color))
		exit_free_parsing(data);
	objects->lctr++;
}
