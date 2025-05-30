#include "../../minirt.h"


bool	fill_in_value(char *value, float *src)
{
	
	*src = ft_atof(value);
	if (!*src)
		return (false);
	if (!(*src >= 0 && *src <= MOL))
		return (ft_putstr_fd("Error\ncheck radius value\n", 2), false);
	return (true);
}

void	case_cy(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[6] != 0)
	{
		ft_putstr_fd("Error\nextra arguments in a line\n", 2);
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

void	case_sp(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("Error\nextra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->sp[objects->spctr].center))
		exit_free_parsing(data);

	if (!fill_in_value(data->lines[i].line[2],
			&objects->sp[objects->spctr].radius))
	{
		exit_free_parsing(data);
	}
	if (!fill_in_RGB(data->lines[i].line[3],
			&objects->sp[objects->spctr].color))
	{
		exit_free_parsing(data);
	}
	objects->spctr++;
}

void	case_pl(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("Error\nextra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->pl[objects->plctr].point))
		exit_free_parsing(data);
	if (!fill_in_orientations(data, i, &objects->pl[objects->plctr].normal))
		exit_free_parsing(data);
	if (!fill_in_RGB(data->lines[i].line[3],
			&objects->pl[objects->plctr].color))
	{
		exit_free_parsing(data);
	}
	objects->plctr++;
}
