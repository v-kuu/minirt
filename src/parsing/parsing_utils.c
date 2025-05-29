#include "../../minirt.h"


void	exit_free_parsing(t_data *data)
{
	free(data->objects->l); // must be free to bonus
	if (data->objects)
		free(data->objects);
	free_lines_arr(data->lines);
	if (data->read_lines)
		free_2d_arr(data->read_lines);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}

void free_lines_arr(t_s_lines *lines)
{
	int i;

	i = 0;
	while (lines[i].line)
	{
		free_2d_arr(lines[i].line);
		lines[i].line = NULL;
		i++;
	}
	free(lines);
	lines = NULL;
}


/*
free 2d arr
*/
void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

/*
to print the error from errno then exit.
*/
void	print_error_exit(void)
{
	ft_putstr_fd("Minirt :", 2);
	ft_putstr_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
