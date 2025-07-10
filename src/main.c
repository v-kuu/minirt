/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:08:55 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 16:09:27 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	check_arguments(argc, argv);
	open_file_read(argv, &data);
	if (!parsing(&data))
		return (ft_free_str_arr(data.read_lines), 1);
	rendering(&data);
	free_objects(&data);
	free_lines_arr(data.lines);
	return (0);
}
