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

#include "../../minirt.h"

float	dot_product(const t_vec3 first, const t_vec3 second)
{
	return (first.x * second.x + first.y * second.y + first.z * second.z);
}

t_vec3	cross_product(const t_vec3 first, const t_vec3 second)
{
	return ((t_vec3){first.y * second.z - first.z * second.y,
		first.z * second.x - first.x * second.z,
		first.x * second.y - first.y * second.x});
}
