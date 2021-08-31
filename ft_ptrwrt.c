/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrwrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:42 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 20:31:54 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ptrwrt(t_dscr **h_w, va_list ap)
{
	unsigned long long		num;
	int						len;
	char					*str;
	char					*leaksprevention;

	len = 0;
	num = va_arg(ap, unsigned long long);
	str = ft_itoa_ptr(num);
	leaksprevention = str;
	if ((*h_w)->flags == '-')
		len += ft_alignum(str, h_w);
	else
		len += ft_putnumright(str, h_w);
	free(leaksprevention);
	return (len);
}
