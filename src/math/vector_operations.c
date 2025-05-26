/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:38:36 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 15:39:19 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

/*
 * Add two vectors together to form a new vector
 */
t_vec3	add_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x + second.x,
		first.y + second.y,
		first.z + second.z});
}

/*
 * Subtract the second vector from the first, forming a new vector
 */
t_vec3	subtract_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x - second.x,
		first.y - second.y,
		first.z - second.z});
}

/*
 * Multiply the scalar parts of two vectors, returning the resulting vector
 */
t_vec3	multiply_vec(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.x * second.x,
		first.y * second.y,
		first.z * second.z});
}

/*
 * Scale a vector by multiplying the components with a scalar
 */
t_vec3	scale_vec(const t_vec3 vector, float scalar)
{
	return ((t_vec3){vector.x * scalar, vector.y * scalar, vector.z * scalar});
}

/*
 * Returns the length of the given vector
 */
float	vec_len(const t_vec3 vector)
{
	return (sqrt(vector.x * vector.x
			+ vector.y * vector.y + vector.z * vector.z));
}
