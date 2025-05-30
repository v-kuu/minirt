#include "../minirt.h"

void	print_lines(t_data *data)
{
	int	i;

	i = 0;
	while (data->read_lines[i])
	{
		if (data->read_lines[i][0] != '\n')
			printf("line[%d] is :%s", i, data->read_lines[i]);
		i++;
	}
}

void	free_objects(t_data *data)
{
	if (data->objects->l)
	{
		free(data->objects->l);
		data->objects->l = NULL;
	}
	if (data->objects->pl)
	{
		free(data->objects->pl);
		data->objects->pl = NULL;
	}
	if (data->objects->cy)
	{
		free(data->objects->cy);
		data->objects->cy = NULL;
	}
	if (data->objects->sp)
	{
		free(data->objects->sp);
		data->objects->sp = NULL;
	}
}


int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	check_arguments(argc, argv);
	open_file_read(argv, data);
	if (!parsing(data))
		return (free_2d_arr(data->read_lines), free(data), 1);
	rendering_loop(data);
	free_objects(data);
	free(data->objects);
	free_lines_arr(data->lines);
	free(data);
	return (0);
}
