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

void	free_objects(t_data *data)
{
	if (data->objects->l)
	{
		free(data->objects->l);
		data->objects->l = NULL;
	}
	if (data->objects->pl)
	{
		free(data->objects->pl);
		data->objects->pl = NULL;
	}
	if (data->objects->cy)
	{
		free(data->objects->cy);
		data->objects->cy = NULL;
	}
	if (data->objects->sp)
	{
		free(data->objects->sp);
		data->objects->sp = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	check_arguments(argc, argv);
	open_file_read(argv, data);
	if (!parsing(data))
		return (free_2d_arr(data->read_lines), free(data), 1);
	rendering_loop(data);
	free_objects(data);
	free(data->objects);
	free_lines_arr(data->lines);
	free(data);
	return (0);
}
