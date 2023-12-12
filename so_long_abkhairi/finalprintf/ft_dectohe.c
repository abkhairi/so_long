/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:46:03 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/24 15:47:52 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenghtx(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num = num / 16;
	}
	return (length);
}

int	ft_dectohex(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	if (num >= 16)
	{
		ft_dectohex(num / 16);
		ft_dectohex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
	return (ft_lenghtx(num));
}
