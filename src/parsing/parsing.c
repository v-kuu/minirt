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
void	numberconvert(float *f, char *str, int *i)
{
	*f = *f * 10;
	(*f) += str[*i] - '0';
	(*i)++;
}

float	decimal_convert(char *decimal_part)
{
	int		j;
	float	d;

	j = 0;
	d = 0;
	if (!decimal_part)
		return (NAN);
	while (decimal_part[j])
	{
		d = d * 10;
		d += decimal_part[j] - '0';
		j++;
	}
	d = d / pow(10, (j));
	return (d);
}

void	handle_minues(int *sign, int *i)
{
	*sign = -1;
	(*i)++;
}
float	ft_atof(char *str)
{
	float	f;
	int		i;
	char	*decimal_part;
	int		sign;

	sign = 1;
	i = 0;
	f = 0;
	decimal_part = NULL;
	if (!str)
		return (NAN);
	if (str[0] == '-')
		handle_minues(&sign, &i);
	while (str[i] && str[i] != '.' && str[i] != '\n')
	{
		numberconvert(&f, str, &i);
	}
	if (str[i] == '.')
	{
		decimal_part = ft_substr(str, i + 1, ft_strlen(str) - 2);
		f = f + decimal_convert(decimal_part);
		free(decimal_part);
	}
	return (f * sign);
}
void	exit_free_parsing(t_data *data)
{
	if (data->read_lines)
		free_2d_arr(data->read_lines);
	if (data->objects)
		free(data->objects);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}

bool	color_validation(t_rgbcolor color)
{
	if (!(color.r >= 0 && color.r <= 255))
		return (ft_putstr_fd("invalid color red value.\n", 2), false);
	if (!(color.g >= 0 && color.g <= 255))
		return (ft_putstr_fd("invalid color green value.\n", 2), false);
	if (!(color.b >= 0 && color.b <= 255))
		return (ft_putstr_fd("invalid color blue value.\n", 2), false);
	return (true);
}
bool	validate_a(t_a_light a)
{
	if (!(a.ratio >= 0 && a.ratio <= 1))
		return (ft_putstr_fd("invalid Ambient light ratio.\n", 2), false);
	if (!color_validation(a.color))
		return (false);
	return (true);
}

void	case_a(t_data *data, t_objects *objects, int i)
{
	char	**rgb;

	rgb = ft_calloc(3, sizeof(char *));
	if (!rgb)
		exit_free_parsing(data);
	objects->a.ratio = ft_atof(data->lines[i].line[1]);
	rgb = ft_split(data->lines[i].line[2], ',');
	if (!rgb)
	{
		free_2d_arr(rgb);
		exit_free_parsing(data);
	}
	objects->a.color.r = ft_atof(rgb[0]);
	objects->a.color.g = ft_atof(rgb[1]);
	objects->a.color.b = ft_atof(rgb[2]);
	if (!objects->a.ratio || !objects->a.color.r || !objects->a.color.g
		|| !objects->a.color.b)
	{
		free_2d_arr(rgb);
		exit_free_parsing(data);
	}
	if (!validate_a(objects->a))
	{
		free_2d_arr(rgb);
		exit_free_parsing(data);
	}
	printf("test a %f\n", objects->a.ratio);
	printf("test a %f\n", objects->a.color.r);
	printf("test a %f\n", objects->a.color.g);
	printf("test a %f\n", objects->a.color.b);
}

bool	parse_to_objects(t_data *data)
{
	int			i;
	t_objects	*objects;

	i = 0;
	objects = ft_calloc(data->lines_counter, sizeof(t_objects *));
	if (!objects)
		return (false);
	data->objects = objects;
	while (data->lines[i].line)
	{
		if (ft_strcmp(data->lines[i].line[0], "A") == 0)
			case_a(data, objects, i);
		// else if (ft_strcmp(data->lines[i].line[0], "C") == 0)
		// 	case_c(data, i);
		// else if (ft_strcmp(data->lines[i].line[0], "L") == 0)
		// 	case_l(data, i);
		// else if (ft_strcmp(data->lines[i].line[0], "pl") == 0)
		// 	case_pl(data, i);
		// else if (ft_strcmp(data->lines[i].line[0], "cy") == 0)
		// 	case_cy(data, i);
		// else if (ft_strcmp(data->lines[i].line[0], "cp") == 0)
		// 	case_sp(data, i);
		// else
		// 	bonus_cases(data);
		i++;
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
	if (!parse_to_objects(data))
		return (free_lines_arr(data->lines), false);
	return (free_2d_arr(data->read_lines), true);
}
