/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:42:11 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/24 15:51:51 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> 

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_dectohex(unsigned int num);
int	ft_dectohe(unsigned int num);
int	ft_dectohexptr(unsigned long long ptr);
int	ft_putnbru(unsigned int n);
int	ft_putstring(char const *s);
int	ft_printf(const char *s, ...);

#endif
