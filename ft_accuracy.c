/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:57:01 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/09 15:57:07 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_acr(char **fmt, t_dscr **h_w, va_list ap)
{
	int arg;

	if (**fmt == '.')
	{
		(*h_w)->acr = 0;
		*fmt += 1;
		if (ft_isdigit(**fmt))
		{
			(*h_w)->acr = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		if (**fmt == '*')
		{
			*fmt += 1;
			arg = va_arg(ap, int);
			if (arg >= 0)
				(*h_w)->acr = arg;
			else
				(*h_w)->acr = -1;
		}
	}
}
