#include "../../minirt.h"

bool	parse_to_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
		{
			data->lines[j].line = ft_split(data->read_lines[i], ' ');
			if (!data->lines[j].line)
				return (free_lines_arr(data->lines), false);
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

bool parse_to_objects(data)
{

}

bool	parsing(t_data *data)
{
	int	lines_counter;

	lines_counter = not_empty_lines(data);
	data->lines = ft_calloc((lines_counter + 1), sizeof(t_s_lines));
	if (!data->lines)
		return (false);
	if (!parse_to_lines(data))
		return (false);
	if (!validation(data))
		return (free_lines_arr(data->lines),false);
	if (!parse_to_objects(data))
		return (free_lines_arr(data->lines),false);
	return (free_2d_arr(data->read_lines), true);
}
