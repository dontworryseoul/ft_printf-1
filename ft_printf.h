/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:43 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/20 04:03:09 by seungyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct    s_flag
{
  int flag_minus;
  int flag_zero;
  int flag_precision;
  int precision;
  int min_width;
  int char_count;
}         t_flag;
t_flag  g_flag;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_c_type(va_list ap);
void	ft_s_type(va_list ap);
void  ft_percent_type(void);
int					ft_printf(const char *format, ...);
char				*ft_itoa_hex(long long n, char type);
void				ft_putchar(char c);
void				*ft_memset(void *ptr, int vlaue, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memchr(const void *ptr, int value, size_t n);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(char *str, int c);
char				*ft_strrchr(char *str, int c);
char				*ft_strdup(char *s);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_atoi(const char *str);
int					ft_memcmp(void *ptr1, void *ptr2, size_t num);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(long long n);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void*(*f)(void*), void(*d)(void*));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);
#endif
