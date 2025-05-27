#include "../minirt.h"



int main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	check_arguments(argc, argv);
	open_file_read(argv, data);
	free_2d_arr(data->read_lines);
	free(data);
	return (0);
}