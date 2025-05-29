#include "../../minirt.h"

bool	fill_in_sp_radius(char *value, t_sphere *sphere)
{
	sphere->radius = ft_atof(value);
	if (!sphere->radius)
		return (false);
	if (!(sphere->radius >= 0 && sphere->radius <= MOL))
		return (ft_putstr_fd("check radius value\n", 2), false);
	return (true);
}

void	case_sp(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->sp[objects->spctr].center))
		exit_free_parsing(data);

	if (!fill_in_sp_radius(data->lines[i].line[2],
			&objects->sp[objects->spctr]))
	{
		exit_free_parsing(data);
	}
	if (!fill_in_RGB(data->lines[i].line[3],
			&objects->sp[objects->spctr].color))
	{
		exit_free_parsing(data);
	}
	printf("sphere info coordinates %f \n",objects->sp[objects->spctr].center.x);
	printf("sphere info coordinates %f \n",		objects->sp[objects->spctr].center.y);
	printf("sphere info coordinates %f \n",		objects->sp[objects->spctr].center.z);
	printf("sphere info coordinates %f \n", objects->sp[objects->spctr].radius);
	printf("sphere info coordinates %f \n", objects->sp[objects->spctr].color.r);
	printf("sphere info coordinates %f \n", objects->sp[objects->spctr].color.g);
	printf("sphere info coordinates %f \n", objects->sp[objects->spctr].color.b);
	objects->spctr++;
}
