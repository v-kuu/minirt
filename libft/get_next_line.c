/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:12:12 by vkuusela          #+#    #+#             */
/*   Updated: 2024/12/05 12:53:46 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_update(int fd, char leftovers[BUFFER_SIZE]);
static char	*ft_rewrite(char *buffer, char leftovers[BUFFER_SIZE]);
static void	ft_save(size_t cutoff, char *buffer, char leftovers[BUFFER_SIZE]);

char	*get_next_line(int fd)
{
	static char	leftovers[BUFFER_SIZE + 1];
	char		*buffer;
	char		*line;
	size_t		length;

	if (fd < 0)
		return (NULL);
	buffer = ft_update(fd, leftovers);
	if (!buffer || !*buffer)
		return (ft_free((void **)&buffer));
	if (!ft_strchr(buffer, '\n'))
		length = ft_strlen(buffer);
	else
		length = ft_strchr(buffer, '\n') - buffer;
	line = ft_substr(buffer, 0, length + 1);
	if (!line)
		return (ft_free((void **)&buffer));
	ft_save(length + 1, buffer, leftovers);
	return (line);
}

static char	*ft_update(int fd, char leftovers[BUFFER_SIZE])
{
	char		*buffer;
	ssize_t		amount_read;

	buffer = (char *)ft_calloc(1, 1);
	if (!buffer)
		return (ft_free((void **)&buffer));
	if (leftovers[0] != '\0')
		buffer = ft_rewrite(buffer, leftovers);
	while (!ft_strchr(buffer, '\n'))
	{
		amount_read = read(fd, leftovers, BUFFER_SIZE);
		if (amount_read < 0)
		{
			ft_free((void **)&buffer);
			return (NULL);
		}
		if (amount_read == 0)
			return (buffer);
		if (amount_read < BUFFER_SIZE)
			leftovers[amount_read] = 0;
		buffer = ft_rewrite(buffer, leftovers);
	}
	return (buffer);
}

static char	*ft_rewrite(char *buffer, char leftovers[BUFFER_SIZE])
{
	char	*new;
	size_t	buffer_len;
	size_t	leftovers_len;

	buffer_len = ft_strlen(buffer);
	leftovers_len = ft_strlen(leftovers);
	new = ft_calloc(buffer_len + leftovers_len + 1, sizeof(char));
	if (!new)
		return (ft_free((void **)&buffer));
	ft_memcpy(new, buffer, buffer_len);
	ft_free((void **)&buffer);
	ft_memcpy(ft_strchr(new, '\0'), leftovers, leftovers_len);
	return (new);
}

static void	ft_save(size_t cutoff, char *buffer, char leftovers[BUFFER_SIZE])
{
	int		index;
	size_t	buffer_len;

	buffer_len = ft_strlen(buffer);
	index = 0;
	while (cutoff < buffer_len && buffer[cutoff])
	{
		leftovers[index] = buffer[cutoff];
		cutoff++;
		index++;
	}
	leftovers[index] = 0;
	ft_free((void **)&buffer);
}
