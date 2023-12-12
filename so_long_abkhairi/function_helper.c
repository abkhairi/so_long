/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:54 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/04 12:24:29 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_pro(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i > 150)
	{
		ft_printf("Error: The map is so long (size ecran)\n");
		exit(1);
	}
	return (i);
}

void	ft_check_rect(char *line)
{
	static int	i;

	if (line && i > 0 && i != ft_strlen_pro(line))
	{
		ft_printf("error\n");
		exit(1);
	}
	i = ft_strlen_pro(line);
}

void	ft_check_if_rectangle_finalline(char **tab)
{
	int	i;
	int	j;

	i = ft_tabsize(tab) - 1;
	while (tab[i])
	{
		j = 0;
		if (i == ft_tabsize(tab) - 1)
		{
			while (tab[i][j] && tab[i][j] == '1')
				j++;
			if (tab[i][j] != '\0')
			{
				ft_printf("map incorrect!\n");
				exit(1);
			}
		}
		i++;
	}
}

void	ft_check_1er_clone(char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = ft_tabsize(tab) - 2;
	while (tab[i] && j > 0)
	{
		k = 0;
		if (tab[i][k] != '1' || tab[i][ft_strlen(tab[i]) - 1] != '1')
		{
			ft_printf("erriuur clone\n");
			exit(1);
		}
		else 
		{
			i++;
			j--;
		}
	}
}
