#include "../../minirt.h"

bool	validate_camera_values(t_objects *objects)
{
	if ((objects->c.coordinates.x > 1 || objects->c.coordinates.x < -1)
		|| (objects->c.coordinates.y > 1 || objects->c.coordinates.y < -1)
		|| (objects->c.coordinates.z > 1 || objects->c.coordinates.z < -1))
	{
		return (ft_putstr_fd("check coordinates vales\n", 2), false);
	}
	if ((objects->c.orientations.x > MOL || objects->c.orientations.x < -MOL)
		|| (objects->c.orientations.y > MOL || objects->c.orientations.y < -MOL)
		|| (objects->c.orientations.z > MOL || objects->c.orientations.z <
			-MOL))
	{
		return (ft_putstr_fd("check Orinetations values\n", 2), false);
	}
	if (!(objects->c.fov >= 0 && objects->c.fov <= 180))
		return (ft_putstr_fd("check fov value\n", 2), false);
	return (true);
}

bool	validate_camera_nan(t_objects *objects)
{
	if (isnan(objects->c.orientations.x) || isnan(objects->c.orientations.y)
		|| isnan(objects->c.orientations.z))
	{
		return (false);
	}
	if (isnan(objects->c.coordinates.x) || isnan(objects->c.coordinates.y)
		|| isnan(objects->c.coordinates.z))
	{
		return (false);
	}
	if (isnan(objects->c.fov))
		return (false);
	return (true);
}

bool	validate_camera(t_objects *objects)
{
	if (!validate_camera_nan(objects))
		return (false);
	if (!validate_camera_values(objects))
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
