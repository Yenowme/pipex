/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:02:35 by kyunkim           #+#    #+#             */
/*   Updated: 2022/01/19 19:09:13 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 400
# endif

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *ptr, int value, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *str, char charset);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putchar(char c);
int					ft_putstr(char *s);
void				ft_putnbr(int n, int *rt);
void				ft_putun(unsigned int n, int *rt);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));

int					get_next_line(int fd, char **line);
#endif