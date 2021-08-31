/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charwrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:57:47 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/09 16:00:22 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_align(char *str, t_dscr **h_w, char c)
{
	int len;

	len = 0;
	if (c == '\0')
	{
		str = ft_fillstr(' ', (*h_w)->width - 1);
		ft_putchar_fd(c, 1);
		ft_putstr_fd(str, 1);
		len = ft_strlen(str) + 1;
	}
	else
	{
		str = ft_fillstr(' ', (*h_w)->width);
		*str = c;
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	free(str);
	return (len);
}

int		ft_putright(char *str, t_dscr **h_w, char c)
{
	int len;

	len = 0;
	if (c == '\0')
	{
		str = ft_fillstr(' ', (*h_w)->width - 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd(c, 1);
		len = ft_strlen(str) + 1;
	}
	else
	{
		str = ft_fillstr(' ', (*h_w)->width);
		*(str + (*h_w)->width - 1) = c;
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	free(str);
	return (len);
}

int		ft_charwrt(t_dscr **h_w, va_list ap)
{
	char *str;
	char c;

	str = NULL;
	c = va_arg(ap, int);
	if ((*h_w)->width > 1)
	{
		if ((*h_w)->flags == ALIGN_LEFT)
			return (ft_align(str, h_w, c));
		else
			return (ft_putright(str, h_w, c));
	}
	else
		ft_putchar_fd(c, 1);
	return (1);
}
