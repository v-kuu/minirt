/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:04:33 by vkuusela          #+#    #+#             */
/*   Updated: 2025/06/18 15:24:29 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_quaternion	create_rotation_quat(t_vec3 from, t_vec3 to)
{
	const t_vec3	from_unit = unit_vec(from);
	const t_vec3	to_unit = unit_vec(to);
	const float		dot = dot_product(from_unit, to_unit);
	t_vec3			rot_axis;
	float			angle;

	if (dot < 1.0f)
	{
		rot_axis = cross_product(from_unit, to_unit);
		angle = acosf(dot);
		return ((t_quaternion){cos(angle / 2),
				rot_axis.x * sin(angle / 2),
				rot_axis.y * sin(angle / 2),
				rot_axis.z * sin(angle / 2)});
	}
	return ((t_quaternion){1, 0, 0, 0});
}

t_vec3	rotate(t_quaternion quat, t_vec3 vec)
{
	t_vec3	rotated;
	float	components[12];
}
