#include "../../minirt.h"

bool	fill_in_value(char *value, float *src)
{
	
	*src = ft_atof(value);
	if (!*src)
		return (false);
	if (!(*src >= 0 && *src <= MOL))
		return (ft_putstr_fd("check radius value\n", 2), false);
	return (true);
}

void	case_cy(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[6] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->cy[objects->cyctr].center))
		exit_free_parsing(data);
	if (!fill_in_orientations(data, i, &objects->cy[objects->cyctr].axis))
		exit_free_parsing(data);
	if (!fill_in_value(data->lines[i].line[3],
			&objects->cy[objects->cyctr].diameter))
	{
		exit_free_parsing(data);
	}
	if (!fill_in_value(data->lines[i].line[4],
			&objects->cy[objects->cyctr].height))
	{
		exit_free_parsing(data);
	}
	if (!fill_in_RGB(data->lines[i].line[5],
			&objects->cy[objects->cyctr].color))
	{
		exit_free_parsing(data);
	}
	objects->cyctr++;
}
 