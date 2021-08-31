/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:40:52 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/07 17:41:45 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	t_dscr		*ft_creation(void)
{
	t_dscr *h_w;

	if (!(h_w = (t_dscr*)malloc(sizeof(t_dscr) * 1)))
		return (0);
	h_w->flags = 0;
	h_w->width = 0;
	h_w->acr = -1;
	h_w->neg = 0;
	return (h_w);
}

int					ft_processing(char **fmt, char **print, va_list ap)
{
	int		len;
	t_dscr	*h_w;

	len = 0;
	h_w = ft_creation();
	ft_flag(fmt, &h_w);
	ft_width(fmt, &h_w, ap);
	ft_acr(fmt, &h_w, ap);
	len += ft_type(fmt, &h_w, ap);
	*print = *fmt;
	free(h_w);
	return (len);
}
