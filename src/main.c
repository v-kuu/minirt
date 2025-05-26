#include "../minirt.h"


void open_file(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Minirt :", 2);
		ft_putstr_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}

	printf("it has a file name, and the file name is correct %s\n", argv[1]);
}


/*
this file to check the filename extention.
if correct and no problems goes to main back. s
*/
void check_filename(char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if (len > 2)
	{
		if (ft_strncmp((argv[1] + (len - 3)),".rt",3 ) != 0)
		{
			ft_putstr_fd("Minirt :", 2);
			ft_putstr_fd("Check the file name please!", 2);
			exit(1);
		}
	}
	else
	{
		ft_putstr_fd("Minirt :", 2);
		ft_putstr_fd("Check the file name please!", 2);
		exit(1);
	}
}

/*
this file to read the arguments, and validates them.abort
if the number of arguments are correct, start checking the filename.
*/
void check_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		check_filename(argv);
	}
	else
	{
		ft_putstr_fd("Minirt :", 2);
		ft_putstr_fd("Check the arguments please!", 2);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	check_arguments(argc, argv);
	open_file(argv);
	return (0);
}