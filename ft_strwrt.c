/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:22:23 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 20:49:35 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_alignstr(char *str, t_dscr **h_w, int strl, char *strw)
{
	if ((*h_w)->acr >= 0)
	{
		if ((*h_w)->width > (*h_w)->acr)
		{
			strw = ft_fillstr(' ', (*h_w)->width);
			ft_memmove(strw, str, (*h_w)->acr);
		}
		else
			strw = ft_substr(str, 0, (*h_w)->acr);
	}
	else
	{
		if ((*h_w)->width > strl)
		{
			strw = ft_fillstr(' ', (*h_w)->width);
			ft_memmove(strw, str, strl);
		}
		else
			strw = ft_substr(str, 0, strl);
	}
	ft_putstr_fd(strw, 1);
	strl = ft_strlen(strw);
	free(strw);
	return (strl);
}

int		ft_putrightstr(char *str, t_dscr **h_w, int strl, char *strw)
{
	if ((*h_w)->acr >= 0)
	{
		if ((*h_w)->width > (*h_w)->acr)
		{
			strw = ft_fillstr(' ', (*h_w)->width);
			ft_memmove(strw + ((*h_w)->width - (*h_w)->acr), str, (*h_w)->acr);
		}
		else
			strw = ft_substr(str, 0, (*h_w)->acr);
	}
	else
	{
		if ((*h_w)->width > strl)
		{
			strw = ft_fillstr(' ', (*h_w)->width);
			ft_memmove(strw + ((*h_w)->width - strl), str, strl);
		}
		else
			strw = ft_substr(str, 0, strl);
	}
	ft_putstr_fd(strw, 1);
	strl = ft_strlen(strw);
	free(strw);
	return (strl);
}

int		ft_strwrt(t_dscr **h_w, va_list ap)
{
	int		len;
	int		strl;
	char	*str;
	char	*strw;
	char	*leakstop;

	len = 0;
	strw = NULL;
	leakstop = NULL;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		leakstop = str;
	}
	strl = ft_strlen(str);
	if ((*h_w)->acr > strl)
		(*h_w)->acr = strl;
	if ((*h_w)->flags == '-')
		len += ft_alignstr(str, h_w, strl, strw);
	else
		len += ft_putrightstr(str, h_w, strl, strw);
	if (leakstop != NULL)
		free(leakstop);
	return (len);
}
