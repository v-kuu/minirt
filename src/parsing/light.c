// #include "../../minirt.h"

// void	case_l(t_data *data, t_objects *objects, int i)
// {
// 	char	**coordinates;

// 	if (data->lines[i].line[4] != 0)
// 	{
// 		ft_putstr_fd("extra arguments in a line\n", 2);
// 		exit_free_parsing(data);
// 	}
// 	coordinates = ft_split(data->lines[i].line[1], ',');
// 	if (!coordinates)
// 		exit_free_parsing(data);
	// fill_in_coordinates(&objects->l->coordinates, coordinates);
	
	// objects->c.fov = ft_atof(data->lines[i].line[3]);
	// free_2d_arr(coordinates);
	// if (!validate_camera(objects))
	// 	exit_free_parsing(data);
	// print_camera(data); // must be deleted
// }