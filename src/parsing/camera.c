#include "../../minirt.h"

bool	validate_coordination(t_vec3 *coords)
{
	if ((coords->x > MOL || coords->x < -MOL) || (coords->y > MOL
			|| coords->y < -MOL) || (coords->z > MOL || coords->z < -MOL))
	{
		return (ft_putstr_fd("Error\ncheck coordinates values\n", 2), false);
	}
	return (true);
}

bool	validate_orientation(t_vec3 *orinets)
{
	if ((orinets->x > 1 || orinets->x < -1) || (orinets->y > 1 || orinets->y <
			-1) || (orinets->z > 1 || orinets->z < -1))
	{
		return (ft_putstr_fd("Error\ncheck Orinetations vales\n", 2), false);
	}
	if ((orinets->x > MOL || orinets->x < -MOL) || (orinets->y > MOL
			|| orinets->y < -MOL) || (orinets->z > MOL || orinets->z < -MOL))
	{
		return (ft_putstr_fd("Error\ncheck Orinetations values\n", 2), false);
	}
	return (true);
}

bool	fill_in_orientations(t_data *data, int i, t_vec3 *orinets)
{
	char	**orientations;

	orientations = ft_split(data->lines[i].line[2], ',');
	if (!orientations)
		exit_free_parsing(data);
	orinets->x = ft_atof(orientations[0]);
	orinets->y = ft_atof(orientations[1]);
	orinets->z = ft_atof(orientations[2]);
	free_2d_arr(orientations);
	if (isnan(orinets->x) || isnan(orinets->y) || isnan(orinets->z))
		return (false);
	if (!validate_orientation(orinets))
		return (false);
	return (true);
}

bool	fill_in_coordinates(t_data *data, int i, t_vec3 *coords)
{
	char	**coordinates;

	coordinates = ft_split(data->lines[i].line[1], ',');
	if (!coordinates)
		return (false);
	coords->x = ft_atof(coordinates[0]);
	coords->y = ft_atof(coordinates[1]);
	coords->z = ft_atof(coordinates[2]);
	free_2d_arr(coordinates);
	if (isnan(coords->x) || isnan(coords->y) || isnan(coords->z))
		return (false);
	if (!validate_coordination(coords))
		return (false);
	return (true);
}

bool	fill_in_c_fov(t_data *data, int i, t_camera *c)
{
	c->fov = ft_atof(data->lines[i].line[3]);
	if (isnan(c->fov))
		exit_free_parsing(data);
	if (!(c->fov >= 0 && c->fov <= 180))
		return (ft_putstr_fd("Error\ncheck fov value\n", 2), false);
	return (true);
}

void	case_c(t_data *data, t_objects *objects, int i)
{
	if (data->lines[i].line[4] != 0)
	{
		ft_putstr_fd("Error\nextra arguments in a line\n", 2);
		exit_free_parsing(data);
	}
	if (!fill_in_coordinates(data, i, &objects->c.coordinates))
		exit_free_parsing(data);
	if (!fill_in_orientations(data, i, &objects->c.orientations))
		exit_free_parsing(data);
	if (!fill_in_c_fov(data, i, &objects->c))
		exit_free_parsing(data);
	// print_camera(data); // must be deleted
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
