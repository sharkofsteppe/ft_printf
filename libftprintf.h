/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:50:41 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/16 18:53:07 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# define SIGN_OF_SPECIFIER '%'
# define END_OF_STRING '\0'
# define ERROR -1
# define ALIGN_LEFT '-'

typedef	struct		s_fmt
{
	char			flags;
	int				width;
	int				acr;
	char			neg;
	int				sl;
}					t_dscr;

int					ft_printf(const char *format, ...);

int					ft_processing(char **fmt, char **printf, va_list ap);
int					ft_type(char **fmt, t_dscr **h_w, va_list ap);
void				ft_width(char **fmt, t_dscr **h_w, va_list ap);
void				ft_acr(char **fmt, t_dscr **h_w, va_list ap);
void				ft_flag(char **fmt, t_dscr **h_w);

int					ft_numwrt(t_dscr **h_w, va_list ap);
int					ft_alignum(char *str, t_dscr **h_w);
char				*pushptr(char *dst, t_dscr **h_w, char *src);
int					ft_putnumright(char *str, t_dscr **h_w);
char				*pushptrrs(char *dst, int start, char *src);
char				*ft_fillernum(char c, int len, t_dscr **h_w, char **str);
char				*ft_fillnumrs(int len, t_dscr **h_w, char **str);
int					ft_uintwrt(t_dscr **h_w, va_list ap);

int					ft_xwrt(char **fmt, t_dscr **h_w, va_list ap);
int					ft_ptrwrt(t_dscr **h_w, va_list ap);

int					ft_charwrt(t_dscr **h_w, va_list ap);
int					ft_strwrt(t_dscr **h_w, va_list ap);
char				*ft_fillstr(char c, int len);

int					ft_prcntwrt(t_dscr **h_w);
#endif
