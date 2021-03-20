/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:43 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/20 19:16:22 by seungyel         ###   ########.fr       */
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
}           t_flag;
t_flag  g_flag;

void	ft_c_type(va_list ap);
void	ft_s_type(va_list ap);
void				ft_percent_type(void);
int					ft_printf(const char *format, ...);
char				*ft_itoa_hex(long long n, char type);
void				ft_putchar(char c);
char				*ft_itoa(long long n);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
char				*ft_strchr(char *str, int c);
#endif
