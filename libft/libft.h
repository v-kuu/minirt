/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:04:32 by vkuusela          #+#    #+#             */
/*   Updated: 2025/07/09 15:24:51 by vkuusela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}				t_list;

int		ft_isalpha(unsigned char character);
int		ft_isdigit(unsigned char character);
int		ft_isalnum(unsigned char character);
int		ft_isascii(unsigned char character);
int		ft_isprint(unsigned char character);
size_t	ft_strlen(const char *string);
void	*ft_memset(void *area, int byte, size_t length);
void	ft_bzero(void *area, size_t length);
void	*ft_memcpy(void *destination, const void *source, size_t length);
void	*ft_memmove(void *destination, const void *source, size_t length);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);
size_t	ft_strlcat(char *destination, const char *source, size_t size);
int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strchr(const char *string, int character);
char	*ft_strrchr(const char *string, int character);
int		ft_strncmp(const char *first, const char *second, size_t length);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memchr(const void *source, int character, size_t length);
int		ft_memcmp(const void *first, const void *second, size_t length);
char	*ft_strnstr(const char *big, const char *little, size_t length);
int		ft_atoi(const char *string);
void	*ft_calloc(size_t elements, size_t size);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *string, unsigned int start, size_t length);
char	*ft_strjoin(char const *prefix, char const *suffix);
char	*ft_strtrim(char const *string, char const *set);
char	**ft_split(char const *source, char character);
char	*ft_itoa(int integer);
char	*ft_strmapi(char const *string, char (*function)(unsigned int, char));
void	ft_striteri(char *string, void (*function)(unsigned int, char *));
void	ft_putchar_fd(char character, int file_descriptor);
void	ft_putstr_fd(char *string, int file_descriptor);
void	ft_putendl_fd(char *string, int file_descriptor);
void	ft_putnbr_fd(int number, int file_descriptor);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **list, t_list *node);
int		ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *node);
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstiter(t_list *list, void (*func)(void *));
t_list	*ft_lstmap(t_list *list, void *(*func)(void *), void (*del)(void *));
int		ft_printf(const char *format, ...);
int		ft_string_print(const char *string);
int		ft_number_print(long number);
int		ft_hex_print(uintptr_t number, char specifier);
char	*get_next_line(int fd);
void	*ft_free(void **ptr);
int		ft_abs(int number);
void	*ft_free_str_arr(char **array);
int		ft_isfloat(int character);

#endif
