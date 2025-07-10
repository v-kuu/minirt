/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:04:39 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/07 15:04:47 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_rgbcolor	add_colors(t_rgbcolor c1, t_rgbcolor c2)
{
	return ((t_rgbcolor){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

t_rgbcolor	multiply_color_by(t_rgbcolor c1, float value)
{
	return ((t_rgbcolor){c1.r * value, c1.g * value, c1.b * value});
}

t_rgbcolor	normalize_color(t_rgbcolor c1)
{
	return ((t_rgbcolor){c1.r / 255.0f, c1.g / 255.0f, c1.b / 255.0f});
}

t_rgbcolor	multiply_colors(t_rgbcolor c1, t_rgbcolor c2)
{
	return ((t_rgbcolor){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
}
