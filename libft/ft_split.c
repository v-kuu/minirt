/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:15:28 by vkuusela          #+#    #+#             */
/*   Updated: 2024/10/31 12:55:05 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *source, unsigned char character);
static char		**ft_free_all(char **array);

char	**ft_split(char const *source, char character)
{
	char			**array;
	size_t			index;
	size_t			length;

	index = 0;
	if (!source || character < 0)
		return (0);
	array = ft_calloc(ft_words(source, character) + 1, sizeof(char *));
	while (*source && array)
	{
		while (*source == character && *source)
			source++;
		if (*source)
		{
			if (!ft_strchr(source, character))
				length = ft_strlen(source);
			else
				length = ft_strchr(source, character) - source;
			array[index++] = ft_substr(source, 0, length);
			if (array[index - 1] == 0)
				array = ft_free_all(array);
			source += length;
		}
	}
	return (array);
}

static size_t	ft_words(char const *source, unsigned char character)
{
	int	count;

	count = 1;
	while (*source != 0)
	{
		if (*source == character)
			count++;
		source++;
	}
	return (count);
}

static char	**ft_free_all(char **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
	return (0);
}
