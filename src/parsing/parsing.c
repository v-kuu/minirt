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

bool	color_validation(t_rgbcolor *color)
{
	if (!(color->r >= 0 && color->r <= 255))
		return (ft_putstr_fd("Error\ninvalid color red value.\n", 2), false);
	if (!(color->g >= 0 && color->g <= 255))
		return (ft_putstr_fd("Error\ninvalid color green value.\n", 2), false);
	if (!(color->b >= 0 && color->b <= 255))
		return (ft_putstr_fd("Error\ninvalid color blue value.\n", 2), false);
	return (true);
}

bool	parse_to_objects(t_data *data)
{
	int			i;
	t_objects	*objects;

	i = 0;
	objects = ft_calloc(1, sizeof(t_objects));
	if (!objects)
		return (false);
	data->objects = objects;
	if(!malloc_all_objects(data))
		return (false);
	while (data->lines[i].line)
	{
		if (ft_strcmp(data->lines[i].line[0], "A") == 0)
			case_a(data, objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "C") == 0)
			case_c(data, objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "L") == 0)
			case_l(data, objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "sp") == 0)
			case_sp(data, objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "pl") == 0)
			case_pl(data,objects, i);
		else if (ft_strcmp(data->lines[i].line[0], "cy") == 0)
			case_cy(data,objects, i);
		// else
		// 	bonus_cases(data);
		i++;
	}
	return (true);
}

void	calculate_counters(t_data *data)
{
	int	i;

	i = 0;
	while (data->lines[i].line)
	{
		if (ft_strcmp(data->lines[i].line[0], "L") == 0)
			data->light_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "pl") == 0)
			data->pl_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "cy") == 0)
			data->cy_counter++;
		else if (ft_strcmp(data->lines[i].line[0], "sp") == 0)
			data->sp_counter++;
		i++;
	}
}
bool	malloc_all_objects(t_data *data)
{
	data->objects->l = ft_calloc(data->light_counter, sizeof(t_light));
	if (!data->objects->l)
		return (false);
	data->objects->sp = ft_calloc(data->sp_counter, sizeof(t_sphere));
	if (!data->objects->sp)
		return (free(data->objects->l), false);
	data->objects->cy = ft_calloc(data->cy_counter, sizeof(t_cylinder));
	if (!data->objects->cy)
		return (free(data->objects->l), free(data->objects->sp), false);
	data->objects->pl = ft_calloc(data->pl_counter, sizeof(t_plane));
	if (!data->objects->pl)
	{
		return (free(data->objects->l), free(data->objects->sp),
			free(data->objects->cy), false);
	}
	return (true);
}
bool	parsing(t_data *data)
{
	data->lines_counter = not_empty_lines(data);
	data->lines = ft_calloc((data->lines_counter + 1), sizeof(t_s_lines));
	if (!data->lines)
		return (false);
	if (!parse_to_lines(data))
		return (false);
	if (!validation(data))
		return (free_lines_arr(data->lines), false);
	calculate_counters(data);
	if (!parse_to_objects(data))
		return (free_lines_arr(data->lines), false);
	return (free_2d_arr(data->read_lines), true);
}
