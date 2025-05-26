/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:28:34 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/26 16:32:31 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

t_color	background_color(t_ray ray)
{
	t_vec3	unit_direction;
	t_color	fraction;

	unit_direction = unit_vec(ray.direction);
	fraction = 0.5 * (unit_direction.y + 1.0);
	return ((1.0 - fraction) * 0xFFFFFFFF + (fraction * 0x77BBFF));
}
