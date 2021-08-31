/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:56:24 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/09 15:56:28 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_flag(char **fmt, t_dscr **h_w)
{
	int zero;
	int minus;

	*fmt += 1;
	zero = 0;
	minus = 0;
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '-')
			minus = 1;
		if (**fmt == '0')
			zero = 1;
		(*fmt)++;
	}
	if (minus == 1)
		(*h_w)->flags = '-';
	if (zero == 1 && minus == 0)
		(*h_w)->flags = '0';
}
