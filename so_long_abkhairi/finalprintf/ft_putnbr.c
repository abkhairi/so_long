/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:34 by abkhairi          #+#    #+#             */
/*   Updated: 2023/09/26 17:52:44 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = count + ft_putchar('-');
		count = count + ft_putchar('2');
		count = count + ft_putnbr(147483648);
	}
	if (n < 0 && n != -2147483648)
	{
		count = count + ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		count = count + ft_putchar(n + '0');
	return (count);
}
