/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcntwrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:38:44 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/15 21:01:22 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		alignprc(char *str, char c, t_dscr **h_w)
{
	int len;

	len = 0;
	str = ft_fillernum(' ', (*h_w)->width, h_w, &str);
	str = ft_memset(str, c, 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		putrightprc(char *str, char c, t_dscr **h_w)
{
	char	*ptr;
	char	a;
	int		len;

	len = 0;
	a = ' ';
	if ((*h_w)->flags == '0')
		a = '0';
	str = ft_fillernum(a, (*h_w)->width, h_w, &str);
	ptr = str;
	str = ft_memset(str + (*h_w)->width - 1, c, 1);
	str = ptr;
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_prcntwrt(t_dscr **h_w)
{
	int		len;
	char	c;
	char	*str;

	str = NULL;
	len = 0;
	c = '%';
	if ((*h_w)->flags == '-')
		len += alignprc(str, c, h_w);
	else
		len += putrightprc(str, c, h_w);
	if ((*h_w)->width == 0)
	{
		ft_putchar_fd(c, 1);
		len += 1;
	}
	return (len);
}
