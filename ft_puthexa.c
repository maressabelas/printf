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

int	ft_puthexa(unsigned int n, char c)
{
	int				count;
	char			*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		count += ft_puthexa(n / 16, c);
	}
	n %= 16;
	if (write(1, &base[n], 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	hexlen;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	len += 2;
	hexlen = ft_puthexa((unsigned long)ptr, 'x');
	if (hexlen < 0)
	{
		return (-1);
	}
	len += hexlen;
	return (len);
}
