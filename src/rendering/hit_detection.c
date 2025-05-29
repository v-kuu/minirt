/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/29 15:29:28 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	sphere_intersection(t_sphere sphere, t_ray ray)
{
	t_vec3	displacement_vec;
	float	square_r;
	float	projection;
	float	square_dist;
	float	discriminant;

	displacement_vec = subtract_vec(sphere.center, ray.origin);
	square_r = dot_product(ray.direction, ray.direction);
	projection = -2.0 * dot_product(ray.direction, displacement_vec);
	square_dist = dot_product(displacement_vec, displacement_vec)
		- sphere.radius * sphere.radius;
	discriminant = projection * projection - 4 * square_r * square_dist;
	return (discriminant >= 0);
}
