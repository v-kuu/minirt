#ifndef MINIRT
# define MINIRT

# define MAX_LINES 200

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	char	**read_lines;
}			t_data;

void		open_file_read(char **argv, t_data *data);
void		check_filename(char **argv);
void		check_arguments(int argc, char **argv);
void		print_error_exit(void);
void 		free_2d_arr(char **arr);

#endif