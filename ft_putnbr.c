/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:01:47 by marbelas          #+#    #+#             */
/*   Updated: 2026/06/13 16:17:57 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		write (1, "-", 1);
		count++;
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		nb %= 10;
	}
	nb += '0';
	write(1, &nb, 1);
	count++;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
