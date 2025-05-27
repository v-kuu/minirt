#include "../minirt.h"

void print_lines(t_data *data)
{
	int i;

	i = 0;

	while (data->read_lines[i])
	{
		if(data->read_lines[i][0] != '\n')
			printf("line[%d] is :%s", i, data->read_lines[i]);
		i++;
	}
}


int main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	check_arguments(argc, argv);
	open_file_read(argv, data);
	// print_lines(data);
	if(!parsing(data))
		{
			free_2d_arr(data->read_lines);
			free(data);
			exit(EXIT_FAILURE);
		}
	free_objects_arr(data->objects);
	free(data->objects);
	free(data);
	return (0);
}
