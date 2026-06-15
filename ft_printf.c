/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:23:28 by marbelas          #+#    #+#             */
/*   Updated: 2026/06/14 18:23:36 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checks(va_list *list, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*list, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*list, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*list, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*list, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(*list, unsigned int), c));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	if (!fmt)
		return (-1);
	va_start(list, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				count += (ft_putchar('%'));
			else
				count += ft_checks(&list, fmt[i]);
		}
		else
			count += ft_putchar(fmt[i]);
		i++;
	}
	va_end(list);
	return (count);
}
