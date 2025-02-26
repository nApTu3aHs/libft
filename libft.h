/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:04:22 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/20 14:46:40 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
#include "ft_math.h"

# define CHECK0RET(x, r) if (!(x)) return (r)
# define CHECK0RET0(x) CHECK0RET(x, 0)
# define CHECK0RET1(x) CHECK0RET(x, -1)
# define CHECK1RET1(x) if ((x) < 0) return (-1)

# ifndef ulong
typedef unsigned long ulong;
# endif

# ifndef uint
typedef unsigned int uint;
# endif

# define ABS(x) (((x) < 0) ? (-(x)) : (x))

# define OR(a, b) (a) ? (a) : (b)
# define AND(a, b) !(a) ? (a) : (b)

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN 1234
#  define BIG_ENDIAN 4321
# endif

# ifdef __APPLE__
#  define MACOS 1
# else
#  define MACOS 0
# endif

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buff
{
	char	*data;
	size_t	len;
	size_t	size;
}					t_buff;

typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_len(void **s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrev(char *str);
char				*ft_memrev(char *str, size_t len);
unsigned char		ft_bitrev(unsigned char b);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_toupper_inplace(char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_putchar(char c);
size_t				ft_putstr(char *s);
size_t				ft_putendl(char *s);
size_t				ft_putnbr(int nb);
size_t				ft_putchar_fd(char c, int fd);
size_t				ft_putstr_fd(char *s, int fd);
size_t				ft_putendl_fd(char *s, int fd);
size_t				ft_putnbr_fd(int nb, int fd);

uint				ft_count_int_digits(long long int n, uint base);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int n, uint base);
char				*ft_itoa_buf(char *s, long long int n, uint base);
char				*ft_ultoa(ulong n);
char				*ft_ultoa_base(ulong n, uint base);
char				*ft_ultoa_buf(char *s, ulong n, uint base);
char				*ft_ftoa(long double n, int decimals);
char				*ft_ftoa_buf(char *s, long double n, int decimals);
char				*ft_double_to_bin(double x);
char				*ft_double_to_bin_buf(char *b, double x);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_realloc(void *ptr, size_t n, size_t len);

void				*t_buff_init(t_buff *b, size_t size);
size_t				t_buff_extend(t_buff *b);
int					t_buff_append(t_buff *b, void *data, size_t len);

void				ft_swap(void **a, void **b);
void				ft_swap_int(int *a, int *b);
void				ft_swap_char(char *a, char *b);

int 				endian();
int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);

#endif
