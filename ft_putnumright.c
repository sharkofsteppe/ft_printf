/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumright.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:18:42 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 18:12:13 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pushptrrs(char *dst, int start, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (dst);
}

char	*acrexist_r(char *strw, t_dscr **h_w, char *str)
{
	if ((*h_w)->width > (*h_w)->acr)
	{
		strw = ft_fillnumrs((*h_w)->width, h_w, &str);
		ft_zeroer(strw + (*h_w)->width - (*h_w)->acr, '0', (*h_w)->acr);
		strw = pushptrrs(strw, (*h_w)->width - (*h_w)->sl, str);
	}
	else
	{
		strw = ft_fillnumrs((*h_w)->acr, h_w, &str);
		ft_zeroer(strw, '0', (*h_w)->acr);
		strw = pushptrrs(strw, (*h_w)->acr - (*h_w)->sl, str);
	}
	return (strw);
}

int		ft_putnumright(char *str, t_dscr **h_w)
{
	char	*strw;
	int		len;

	strw = NULL;
	len = 0;
	(*h_w)->sl = ft_strlen(str);
	if ((*h_w)->acr >= (*h_w)->sl)
		strw = acrexist_r(strw, h_w, str);
	else
	{
		if ((*h_w)->width > (*h_w)->sl)
		{
			strw = ft_fillnumrs((*h_w)->width, h_w, &str);
			ft_memmove(strw + ((*h_w)->width - (*h_w)->sl), str, (*h_w)->sl);
		}
		else
			strw = ft_substr(str, 0, (*h_w)->sl);
	}
	ft_putstr_fd(strw, 1);
	len = ft_strlen(strw);
	free(strw);
	return (len);
}
