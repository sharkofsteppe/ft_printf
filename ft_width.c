/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:56:41 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/09 15:56:46 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_width(char **fmt, t_dscr **h_w, va_list ap)
{
	int arg;

	if (ft_isdigit(**fmt))
		(*h_w)->width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '*')
	{
		*fmt += 1;
		arg = va_arg(ap, int);
		if (arg < 0)
		{
			(*h_w)->flags = '-';
			(*h_w)->width = -1 * arg;
		}
		else
			(*h_w)->width = arg;
	}
}
