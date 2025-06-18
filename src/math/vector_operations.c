/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:38:36 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/18 14:15:20 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_vec3	add_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x + second.x, first.y + second.y, first.z
		+ second.z});
}

t_vec3	subtract_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x - second.x, first.y - second.y, first.z
		- second.z});
}

t_vec3	multiply_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x * second.x, first.y * second.y, first.z
		* second.z});
}

t_vec3	scale_vec(const t_vec3 vector, float scalar)
{
	return ((t_vec3){vector.x * scalar, vector.y * scalar, vector.z * scalar});
}

t_vec3	divide_vec(const t_vec3 vector, float scalar)
{
	return ((t_vec3){vector.x / scalar, vector.y / scalar, vector.z / scalar});
}
