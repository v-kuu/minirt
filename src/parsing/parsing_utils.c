#include "../../minirt.h"


void free_objects_arr(t_object *objects)
{
	int i;

	i = 0;
	while (objects[i].object)
	{
		free_2d_arr(objects[i].object);
		objects[i].object = NULL;
		i++;
	}
	free(objects);
	objects = NULL;
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