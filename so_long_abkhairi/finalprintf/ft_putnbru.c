/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:24:52 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/22 13:25:28 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		count = count + ft_putchar(n + '0');
	return (count);
}
