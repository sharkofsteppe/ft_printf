/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillernum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:27:07 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/11 17:27:11 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_fillernum(char c, int len, t_dscr **h_w, char **str)
{
	char	*newstring;
	int		i;

	i = 0;
	if ((*h_w)->acr > (*h_w)->sl && (*h_w)->acr >= (*h_w)->width &&
		(*h_w)->neg == '-')
		len++;
	if (!(newstring = (char*)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	if ((*h_w)->neg == '-' && (*h_w)->flags == '-' && (*h_w)->acr > (*h_w)->sl)
	{
		newstring[i] = '-';
		if ((*h_w)->width > (*h_w)->acr || (*h_w)->acr > (*h_w)->sl)
			(*h_w)->sl -= 2;
		else
			(*h_w)->sl -= 1;
		i += 1;
		(*str)++;
	}
	while (i < len)
	{
		newstring[i] = c;
		i++;
	}
	return (newstring);
}
