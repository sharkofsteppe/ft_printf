/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:15:21 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 20:06:24 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pushptr(char *dst, t_dscr **h_w, char *src)
{
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	start = 0;
	if ((*h_w)->neg == '-' && (*h_w)->width > (*h_w)->acr &&
		(*h_w)->acr > (*h_w)->sl)
		start = (*h_w)->acr - (*h_w)->sl;
	else
		start = (*h_w)->acr - (*h_w)->sl;
	while (i < start)
		i++;
	while (src[j] != '\0')
		dst[i++] = src[j++];
	return (dst);
}

char	*ft_thatcase(char *strw, t_dscr **h_w, char *str)
{
	int i;

	i = 1;
	(*h_w)->sl -= 1;
	if (!(strw = (char*)ft_calloc(sizeof(char), ((*h_w)->acr +
		((*h_w)->acr - (*h_w)->sl) + 1))))
		return (NULL);
	strw[0] = '-';
	str += 1;
	(*h_w)->sl -= 1;
	if ((*h_w)->width > (*h_w)->acr)
		(*h_w)->width += (*h_w)->width - ((*h_w)->acr - (*h_w)->sl);
	ft_zeroer(strw, '0', (*h_w)->acr);
	strw = pushptr(strw, h_w, str);
	return (strw);
}

char	*acrexist_l(char *strw, t_dscr **h_w, char *str)
{
	if ((*h_w)->acr == (*h_w)->sl && (*h_w)->neg == '-')
	{
		strw = ft_thatcase(strw, h_w, str);
		return (strw);
	}
	if ((*h_w)->width > (*h_w)->acr)
	{
		strw = ft_fillernum(' ', (*h_w)->width, h_w, &str);
		ft_zeroer(strw, '0', (*h_w)->acr);
		strw = pushptr(strw, h_w, str);
	}
	else
	{
		strw = ft_fillernum(' ', (*h_w)->acr, h_w, &str);
		ft_zeroer(strw, '0', (*h_w)->acr);
		strw = pushptr(strw, h_w, str);
	}
	return (strw);
}

int		ft_alignum(char *str, t_dscr **h_w)
{
	char	*strw;
	int		len;

	strw = NULL;
	len = 0;
	(*h_w)->sl = ft_strlen(str);
	if ((*h_w)->acr >= (*h_w)->sl)
		strw = acrexist_l(strw, h_w, str);
	else
	{
		if ((*h_w)->width > (*h_w)->sl)
		{
			strw = ft_fillernum(' ', (*h_w)->width, h_w, &str);
			ft_memmove(strw, str, (*h_w)->sl);
		}
		else
		{
			strw = ft_substr(str, 0, (*h_w)->sl);
		}
	}
	ft_putstr_fd(strw, 1);
	len = ft_strlen(strw);
	free(strw);
	return (len);
}
