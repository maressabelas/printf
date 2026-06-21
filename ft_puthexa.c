/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:03:21 by marbelas          #+#    #+#             */
/*   Updated: 2026/06/13 16:17:49 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char c)
{
	int				count;
	char			*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthexa(n / 16, c);
	n %= 16;
	write(1, &base[n], 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	len += ft_puthexa((unsigned long)ptr, 'x');
	return (len);
}
