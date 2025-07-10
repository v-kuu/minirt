/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:04:33 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 16:10:18 by vkuusela         ###   ########.fr       */
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
	const t_vec3	q_xyz = (t_vec3){quat.x, quat.y, quat.z};
	const float		w = quat.w;
	t_vec3			rotated;
	t_vec3			temp;

	rotated = scale_vec(q_xyz, 2.0f * dot_product(q_xyz, vec));
	temp = scale_vec(vec, w * w - dot_product(q_xyz, q_xyz));
	rotated = add_vec(rotated, temp);
	temp = scale_vec(scale_vec(cross_product(q_xyz, vec), w), 2.0f);
	rotated = add_vec(rotated, temp);
	return (rotated);
}

t_quaternion	normalize_quat(t_quaternion quat)
{
	const float	len = sqrtf(quat.w * quat.w + quat.x * quat.x
			+ quat.y * quat.y + quat.z * quat.z);

	return ((t_quaternion){quat.w / len, quat.x / len,
		quat.y / len, quat.z / len});
}

t_quaternion	inverse_quat(t_quaternion quat)
{
	return ((t_quaternion){quat.w, -quat.x, -quat.y, -quat.z});
}
