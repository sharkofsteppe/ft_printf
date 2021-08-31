/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillnumrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:41:56 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 20:05:50 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_withacr(int len, char c, t_dscr **h_w, char **str)
{
	int		i;
	char	*newstring;

	i = 0;
	if ((*h_w)->acr > (*h_w)->sl && (*h_w)->acr >= (*h_w)->width &&
		(*h_w)->neg == '-')
		len += 1;
	if (!(newstring = (char*)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (i == len - (*h_w)->acr - 1 && (*h_w)->neg == '-')
		{
			newstring[i] = '-';
			if ((*h_w)->acr >= (*h_w)->width && (*h_w)->acr > (*h_w)->sl)
				(*h_w)->sl -= 2;
			else
				(*h_w)->sl -= 1;
			(*str) += 1;
			i++;
		}
		newstring[i] = c;
		i++;
	}
	return (newstring);
}

char	*ft_withoutacr(int len, char c, t_dscr **h_w, char **str)
{
	int		i;
	char	*newstring;

	i = 0;
	if (!(newstring = (char*)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	if ((*h_w)->flags == '0' && (*h_w)->neg == '-')
	{
		newstring[i] = '-';
		(*str) += 1;
		(*h_w)->sl -= 1;
		i++;
	}
	while (i < len)
	{
		newstring[i] = c;
		i++;
	}
	return (newstring);
}

void	ft_reallyspecial(t_dscr **h_w, int *flag)
{
	if ((*h_w)->acr == (*h_w)->sl && (*h_w)->neg == '-')
	{
		(*h_w)->sl -= 1;
		*flag = 1;
	}
}

char	*ft_fillnumrs(int len, t_dscr **h_w, char **str)
{
	int		flag;
	char	*newstring;
	char	c;

	newstring = NULL;
	c = ' ';
	flag = 0;
	if ((*h_w)->acr >= 0)
	{
		if ((*h_w)->acr == (*h_w)->sl && (*h_w)->neg == '-')
			ft_reallyspecial(h_w, &flag);
		if ((*h_w)->acr >= 0 && (*h_w)->acr < (*h_w)->sl)
			(*h_w)->acr = (*h_w)->sl - 1;
		newstring = ft_withacr(len, c, h_w, str);
		if (flag == 1)
			(*h_w)->sl += 1;
	}
	else
	{
		if ((*h_w)->flags == '0')
			c = '0';
		newstring = ft_withoutacr(len, c, h_w, str);
	}
	return (newstring);
}
