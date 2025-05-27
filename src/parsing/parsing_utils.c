#include "../../minirt.h"

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
