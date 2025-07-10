/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:40:39 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/08 14:40:41 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	print_exit_read(char *msg, t_data *data, int fd)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Minirt: ", 2);
	ft_putstr_fd(msg, 2);
	close(fd);
	ft_free_str_arr(data->read_lines);
	exit(EXIT_FAILURE);
}

void	read_file(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->read_lines = ft_calloc(MAX_LINES + 1, sizeof(char *));
	if (!data->read_lines)
		print_exit_read("Malloc fails", data, fd);
	while (i < MAX_LINES)
	{
		data->read_lines[i] = get_next_line(fd);
		if (!data->read_lines[i])
			break ;
		i++;
	}
	if (i >= MAX_LINES)
		print_exit_read("More lines than the max numbers allowed", data, fd);
}

/*
this to open the file, and check if the open goes well or
return an error with details because of the error.
*/
void	open_file_read(char **argv, t_data *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_exit();
	read_file(fd, data);
	close(fd);
}

/*
this file to check the filename extention.
if correct and no problems goes to main back. s
*/
void	check_filename(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len > 2)
	{
		if (ft_strncmp((argv[1] + (len - 3)), ".rt", 3) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Check the file name please!\n", 2);
			exit(1);
		}
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Check the file name please!\n", 2);
		exit(1);
	}
}

/*
this file to read the arguments, and validates them.abort
if the number of arguments are correct, start checking the filename.
*/
void	check_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		check_filename(argv);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Minirt: Check the arguments please!\n", 2);
		exit(1);
	}
}
