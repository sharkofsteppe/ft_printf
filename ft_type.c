/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:16:48 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 19:56:05 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_type(char **fmt, t_dscr **h_w, va_list ap)
{
	int	len;

	len = 0;
	if (**fmt == 'c')
		len += ft_charwrt(h_w, ap);
	if (**fmt == 's')
		len += ft_strwrt(h_w, ap);
	if (**fmt == 'd')
		len += ft_numwrt(h_w, ap);
	if (**fmt == 'i')
		len += ft_numwrt(h_w, ap);
	if (**fmt == 'u')
		len += ft_uintwrt(h_w, ap);
	if (**fmt == 'x')
		len += ft_xwrt(fmt, h_w, ap);
	if (**fmt == 'X')
		len += ft_xwrt(fmt, h_w, ap);
	if (**fmt == 'p')
		len += ft_ptrwrt(h_w, ap);
	if (**fmt == '%')
		len += ft_prcntwrt(h_w);
	return (len);
}
