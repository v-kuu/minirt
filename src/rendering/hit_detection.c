/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:06 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/29 15:45:07 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	sphere_intersection(t_sphere sphere, t_ray ray)
{
	t_vec3	displacement_vec;
	float	square_ray;
	float	projection;
	float	square_dist;
	float	discriminant;

	displacement_vec = subtract_vec(sphere.center, ray.origin);
	square_ray = dot_product(ray.direction, ray.direction);
	projection = dot_product(ray.direction, displacement_vec);
	square_dist = dot_product(displacement_vec, displacement_vec)
		- sphere.radius * sphere.radius;
	discriminant = projection * projection - square_ray * square_dist;
	if (discriminant < 0)
		return (-1.0);
	else
		return (projection - sqrt(discriminant) / square_ray);
}
