/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:16 by vkuusela          #+#    #+#             */
/*   Updated: 2024/11/15 17:54:28 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parse(va_list arguments, const char *format);
static int	ft_convert(va_list content, char specifier);
static bool	ft_is_valid(char specifier);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		total;

	if (!format)
		return (-1);
	va_start(arguments, format);
	total = ft_parse(arguments, format);
	va_end(arguments);
	return (total);
}

static int	ft_parse(va_list arguments, const char *format)
{
	int	total;
	int	temp;

	total = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%' && ft_is_valid(format[1]))
		{
			temp = ft_convert(arguments, *(format + 1));
			format += 2;
		}
		else if (*format == '%')
			return (-1);
		else
		{
			temp = write(1, format, 1);
			format++;
		}
		if (temp < 0)
			return (-1);
		total += temp;
	}
	return (total);
}

static int	ft_convert(va_list content, char specifier)
{
	if (specifier == 'c')
		return (write(1, &(unsigned char){va_arg(content, int)}, 1));
	else if (specifier == 's')
		return (ft_string_print(va_arg(content, const char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_number_print(va_arg(content, int)));
	else if (specifier == 'u')
		return (ft_number_print((va_arg(content, unsigned int))));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hex_print(va_arg(content, unsigned int), specifier));
	else if (specifier == 'p')
		return (ft_hex_print(va_arg(content, uintptr_t), specifier));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}

static bool	ft_is_valid(char specifier)
{
	char	*set;

	set = "csdiuxXp%";
	while (*set)
	{
		if (*set == specifier)
			return (true);
		set++;
	}
	return (false);
}
