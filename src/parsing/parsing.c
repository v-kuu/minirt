#include "../../minirt.h"

bool	parse_to_objects(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
		{
			data->objects[j].object = ft_split(data->read_lines[i], ' ');
			if (!data->objects[j].object)
				return (free_objects_arr(data->objects), false);
			j++;
		}
		i++;
	}
	return (true);
}

int	not_empty_lines(t_data *data)
{
	int	i;
	int	lines_counter;

	i = 0;
	lines_counter = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
			lines_counter++;
		i++;
	}
	return (lines_counter);
}

bool	parsing(t_data *data)
{
	int	lines_counter;

	lines_counter = not_empty_lines(data);
	data->objects = ft_calloc((lines_counter + 1), sizeof(t_object *));
	if (!data->objects)
		return (false);
	if (!parse_to_objects(data))
		return (false);
	if (!validation(data))
		return (free_objects_arr(data->objects),false);
	return (free_2d_arr(data->read_lines), true);
}
