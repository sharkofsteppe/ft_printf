/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:38:55 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 20:21:08 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nnan(char *str, int len, t_dscr **h_w)
{
	str = (char*)calloc(sizeof(char), (*h_w)->width + 1);
	while (len < (*h_w)->width)
	{
		str[len] = ' ';
		len++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int		ft_numwrt(t_dscr **h_w, va_list ap)
{
	int		len;
	int		num;
	char	*str;
	char	*leaksprevention;

	len = 0;
	str = NULL;
	num = va_arg(ap, int);
	if (num < 0)
		(*h_w)->neg = '-';
	if (num == 0 && (*h_w)->acr == 0)
		return (ft_nnan(str, len, h_w));
	str = ft_itoa(num);
	leaksprevention = str;
	if ((*h_w)->flags == '-')
		len += ft_alignum(str, h_w);
	else
		len += ft_putnumright(str, h_w);
	free(leaksprevention);
	return (len);
}
