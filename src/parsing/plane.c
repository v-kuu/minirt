#include "../../minirt.h"

void	case_pl(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
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
