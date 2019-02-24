/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:20:08 by ppetitea          #+#    #+#             */
/*   Updated: 2019/02/23 13:39:41 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# ifdef __linux__
#  include <sys/types.h>
# endif

# define BUFF_SIZE 2048

typedef uint8_t		t_u8;
typedef int8_t		t_i8;
typedef uint16_t	t_u16;
typedef int16_t		t_i16;
typedef uint32_t	t_u32;
typedef int32_t		t_i32;
typedef uint64_t	t_u64;
typedef int64_t		t_i64;

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list		*next;
}				t_list;

typedef struct			s_fd
{
	int			fd;
	char			*s;
}				t_fd;

typedef struct			s_rgb
{
	t_u8	r;
	t_u8	g;
	t_u8	b;
}						t_rgb;

typedef struct			s_hsv
{
	float	h;
	float	s;
	float	v;
}						t_hsv;

int					contains_char(char	*string, char c);
char				*ft_strcdup(char *string, char c);
size_t				ft_strlen(const char *s);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_is_number(char c);
int					ft_is_space(char c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, void *src, size_t len);
void				*ft_memset(void *s, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *sr, size_t len);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hay, const char *nee, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *hay, const char *nee);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
char				*ft_strcdup(char *string, char c);
int					contains_char(char *string, char c);
t_rgb				ft_rgb(t_u8 r, t_u8 g, t_u8 b);
t_u32				ft_rgb_to_int(t_rgb color);
t_rgb				ft_int_to_rgb(t_u32 color);
t_hsv				ft_hsv(float h, float s, float v);
t_rgb				ft_hsv_to_rgb(t_hsv color);

#endif
