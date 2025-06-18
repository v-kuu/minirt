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
	const t_vec3	from_unit = normalize(from);
	const t_vec3	to_unit = normalize(to);
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

t_vec3	rotate_by_quat(t_quaternion quat, t_vec3 vec)
{
	t_vec3	rotated;
	float	xyz[3];
	float	mat[3][3];

	xyz[0] = quat.x * 2;
	xyz[1] = quat.y * 2;
	xyz[2] = quat.z * 2;
	mat[0][0] = quat.x * xyz[0];
	mat[0][1] = quat.y * xyz[1];
	mat[0][2] = quat.z * xyz[2];
	mat[1][0] = quat.x * xyz[1];
	mat[1][1] = quat.x * xyz[2];
	mat[1][2] = quat.y * xyz[2];
	mat[2][0] = quat.w * xyz[0];
	mat[2][1] = quat.w * xyz[1];
	mat[2][2] = quat.w * xyz[2];

	rotated.x = (1 - (mat[0][1] + mat[0][2])) * vec.x + (mat[1][0] - mat[2][2])
		* vec.y + (mat[1][1] + mat[2][1]) * vec.z;
	rotated.y = (mat[1][0] + mat[2][2]) * vec.x + (1 - (mat[0][0] + mat[0][2]))
		* vec.y + (mat[1][2] - mat[2][0]) * vec.z;
	rotated.z = (mat[1][1] - mat[2][1]) * vec.x + (mat[1][2] + mat[2][2])
		* vec.y + (1 - (mat[0][0] + mat[0][1])) * vec.z;
	return (rotated);
}
