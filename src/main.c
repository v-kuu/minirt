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
		return (free_2d_arr(data->read_lines), free(data), 1);
	
	free_lines_arr(data->lines);
	free(data);
	return (0);
}
