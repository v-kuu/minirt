/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_products.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:22:16 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 15:22:46 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

/*
 * Calculates the dot product between 2 vectors. The dot product tells us
 * information abot the angle between the vectors.
 * A return value of > 0 means the angle is less than 90°, 0 means it is exactly
 * 90°, and a value of < 0 means the angle is more than 90°, for example.
 */
float	dot_product(const t_vec3 first, const t_vec3 second)
{
	return (first.x * second.x + first.y * second.y + first.z * second.z);
}

/*
 * Given 2 vectors, the cross product can be seen as the normal of the plane
 * containing the two vectors. For example, the cross product of (1, 0, 0) and
 * (0, 1, 0) is equal to (0, 0, 1)
 */
t_vec3	cross_product(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.y * second.z - first.z * second.y,
		first.z * second.y - first.x * second.z,
		first.x * second.y - first.y * second.x});
}
