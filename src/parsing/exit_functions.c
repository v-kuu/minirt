/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:37:11 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/09 15:37:37 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

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
	free(data->objects);
}

void	exit_free_parsing(t_data *data)
{
	free_objects(data);
	free_lines_arr(data->lines);
	if (data->read_lines)
		ft_free_str_arr(data->read_lines);
	exit(EXIT_FAILURE);
}

/*
to print the error from errno then exit.
*/
void	print_error_exit(void)
{
	perror("Minirt");
	exit(EXIT_FAILURE);
}
