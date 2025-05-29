#include "../../minirt.h"

bool	validate_camera(t_objects *objects)
{
	
	if ((objects->c.orientations.x == NAN) || (objects->c.orientations.y == NAN)
		|| (objects->c.orientations.z == NAN))
	{
		return (false);
	}
	if ((objects->c.coordinates.x == NAN) || (objects->c.coordinates.y == NAN)
		|| (objects->c.coordinates.z == NAN))
	{
		return (false);
	}
	if ((objects->c.fov == NAN))
		return (false);
	return (true);
}

void	fill_in_orientations(t_objects *objects, char **orientations)
{
	objects->c.orientations.x = ft_atof(orientations[0]);
	objects->c.orientations.y = ft_atof(orientations[1]);
	objects->c.orientations.z = ft_atof(orientations[2]);
}

void	fill_in_coordinates(t_objects *objects, char **coordinates)
{
	objects->c.coordinates.x = ft_atof(coordinates[0]);
	objects->c.coordinates.y = ft_atof(coordinates[1]);
	objects->c.coordinates.z = ft_atof(coordinates[2]);
}

void	case_c(t_data *data, t_objects *objects, int i)
{
	char	**coordinates;
	char	**orientations;

	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("extra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	coordinates = ft_split(data->lines[i].line[1], ',');
	if (!coordinates)
		exit_free_parsing(data);
	fill_in_coordinates(objects, coordinates);
	orientations = ft_split(data->lines[i].line[2], ',');
	if (!orientations)
	{
		free_2d_arr(coordinates);
		exit_free_parsing(data);
	}
	fill_in_orientations(objects, orientations);
	objects->c.fov = ft_atof(data->lines[i].line[3]);
	free_2d_arr(coordinates);
	free_2d_arr(orientations);
	if (!validate_camera(objects))
		exit_free_parsing(data);
	print_camera(data); // must be deleted
}

void	print_camera(t_data *data)
{
	printf("Camera info coordinates %f \n", data->objects->c.coordinates.x);
	printf("Camera info coordinates %f \n", data->objects->c.coordinates.y);
	printf("Camera info coordinates %f \n", data->objects->c.coordinates.z);
	printf("Camera info orientations %f \n", data->objects->c.orientations.x);
	printf("Camera info orientations %f \n", data->objects->c.orientations.y);
	printf("Camera info orientations %f \n", data->objects->c.orientations.z);
	printf("Camera info FOV %f \n", data->objects->c.fov);
}
