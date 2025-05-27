#include "../../minirt.h"

static bool	line_parsing(t_data *data, int i)
{
	printf("line %s\n", data->read_lines[i]);
	return (true);
}

bool	parsing(t_data *data)
{
	int i;
	int j;
	const char *valid_identifiers[] = {"A", "C", "pl", "L", "sp", "cy", "\n"};

	i = 0;
	j = 0;
	while (data->read_lines[i])
	{
		j = 0;
		while (valid_identifiers[j])
		{
			if (ft_strchr(valid_identifiers[j], data->read_lines[i][0]) != 0)
				return(print_error_exit(), false);
			else
				line_parsing(data, i);
			j++;
		}
		// if (data->read_lines[i][0] != '\n') line_parsing(data, i);
		i++;
	}
	return (true);
}