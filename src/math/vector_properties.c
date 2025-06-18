/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:59:23 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 18:01:18 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	vec_len(const t_vec3 vector)
{
	return (sqrtf(vector.x * vector.x
			+ vector.y * vector.y + vector.z * vector.z));
}

t_vec3	normalize(const t_vec3 vector)
{
	return (divide_vec(vector, vec_len(vector)));
}
