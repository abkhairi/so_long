/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:59:34 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/23 18:07:22 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char d, va_list sptr)
{
	int	count;

	count = 0;
	if (d == 's')
		count += ft_putstring(va_arg(sptr, char *));
	else if (d == 'c')
		count += ft_putchar(va_arg(sptr, int));
	else if (d == 'd' || d == 'i')
		count += ft_putnbr(va_arg(sptr, int));
	else if (d == 'p')
		count += ft_dectohexptr(va_arg(sptr, unsigned long long));
	else if (d == 'x')
		count += ft_dectohex(va_arg(sptr, unsigned int));
	else if (d == 'X')
		count += ft_dectohe(va_arg(sptr, unsigned int));
	else if (d == 'u')
		count += ft_putnbru(va_arg(sptr, unsigned int));
	else if (d == '%')
		count += ft_putchar('%');
	else
		ft_putchar(d);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	sptr;

	if ((write(1, "0", 0) == -1))
		return (-1);
	i = 0;
	j = 0;
	va_start(sptr, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			j += ft_format(s[i], sptr);
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end (sptr);
	return (j);
}
