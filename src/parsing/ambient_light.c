#include "../../minirt.h"

bool	validate_a(t_a_light a)
{
	if (!(a.ratio >= 0 && a.ratio <= 1))
		return (ft_putstr_fd("invalid Ambient light ratio.\n", 2), false);
	if (!color_validation(a.color))
		return (false);
	return (true);
}

void	case_a(t_data *data, t_objects *objects, int i)
{
	char	**rgb;

	rgb = NULL;
	if (data->lines[i].line[3] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	objects->a.ratio = ft_atof(data->lines[i].line[1]);
	rgb = ft_split(data->lines[i].line[2], ',');
	if (!rgb)
	{
		free_2d_arr(rgb);
		exit_free_parsing(data);
	}
	objects->a.color.r = ft_atof(rgb[0]);
	objects->a.color.g = ft_atof(rgb[1]);
	objects->a.color.b = ft_atof(rgb[2]);
	if (!objects->a.ratio || !objects->a.color.r || !objects->a.color.g
		|| !objects->a.color.b || !validate_a(objects->a))
	{
		free_2d_arr(rgb);
		exit_free_parsing(data);
	}
	free_2d_arr(rgb);
}
