/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:50:09 by gesperan          #+#    #+#             */
/*   Updated: 2020/12/16 18:54:40 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ft_go_ahead(char **fmt, char **print, va_list ap,
									int *len_for_cut)
{
	int		length;
	char	*string_to_write;

	length = *len_for_cut;
	string_to_write = ft_substr(*print, 0, *len_for_cut);
	ft_putstr_fd(string_to_write, 1);
	free(string_to_write);
	length += ft_processing(fmt, print, ap);
	*len_for_cut = 0;
	if (**fmt != END_OF_STRING)
		*fmt += 1;
	*print = *fmt;
	return (length);
}

static	void	ft_step_by_step(char **fmt, char **print, int *len_for_cut,
									int *length)
{
	char *string_to_write;

	*fmt += 1;
	*len_for_cut += 1;
	if (**fmt == END_OF_STRING)
	{
		string_to_write = ft_substr(*print, 0, *len_for_cut);
		ft_putstr_fd(string_to_write, 1);
		free(string_to_write);
		*length += *len_for_cut;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int		length;
	int		len_for_cut;
	char	*fmt;
	char	*print;

	fmt = (char *)format;
	print = fmt;
	length = 0;
	len_for_cut = 0;
	va_start(ap, format);
	while (*fmt)
	{
		if (*fmt == SIGN_OF_SPECIFIER)
			length += ft_go_ahead(&fmt, &print, ap, &len_for_cut);
		else
			ft_step_by_step(&fmt, &print, &len_for_cut, &length);
	}
	va_end(ap);
	return (length);
}
