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
	int				aux;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		aux = ft_puthexa(n / 16, c);
		if (aux == -1)
        	return (-1);
		count += aux;
	}
	n %= 16;
	if (write(1, &base[n], 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int	ft_puthexa_long(unsigned long n)
{
	int	count;
	int	aux;
	char *base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		aux = ft_puthexa_long(n / 16);
		if (aux == -1)
			return (-1);
		count += aux;
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
		if (write(1, "(nil)", 5) == -1);
			return (-1);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	hexlen = ft_puthexa_long((unsigned long)ptr);
	if (hexlen < 0)
		return (-1);
	len += hexlen;
	return (len);
}
