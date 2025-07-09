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

void	exit_free_parsing(t_data *data)
{
	free(data->objects->l);
	if (data->objects)
		free(data->objects);
	free_lines_arr(data->lines);
	if (data->read_lines)
		ft_free_str_arr(data->read_lines);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
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
