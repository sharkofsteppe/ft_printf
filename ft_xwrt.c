/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xwrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:18:13 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/16 18:54:24 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	getupx(char **str)
{
	char *ptr;

	ptr = *str;
	while (**str != '\0')
	{
		if (ft_isalpha(**str))
			**str = ft_toupper(**str);
		(*str)++;
	}
	*str = ptr;
}

int		ft_xnnan(char *str, int len, t_dscr **h_w)
{
	str = (char*)calloc(sizeof(char), (*h_w)->width + 1);
	while (len < (*h_w)->width)
	{
		str[len] = ' ';
		len++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int		ft_xwrt(char **fmt, t_dscr **h_w, va_list ap)
{
	int		len;
	int		num;
	char	*str;
	char	*leaksprevention;

	len = 0;
	str = NULL;
	num = va_arg(ap, int);
	if (num == 0 && (*h_w)->acr == 0)
		return (ft_xnnan(str, len, h_w));
	str = ft_itoa_base(num);
	leaksprevention = str;
	if (**fmt == 'X')
		getupx(&str);
	if ((*h_w)->flags == '-')
		len += ft_alignum(str, h_w);
	else
		len += ft_putnumright(str, h_w);
	free(leaksprevention);
	return (len);
}
