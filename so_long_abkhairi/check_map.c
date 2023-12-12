/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:29:31 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/03 11:54:03 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_caractere(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1' || tab[i][j] == '0' || tab[i][j] == 'P' 
			|| tab[i][j] == 'C' || tab[i][j] == 'E')
			{
				j++;
			}
			else if (tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != 'P' 
			&& tab[i][j] != 'C' && tab[i][j] != 'E')
			{
				ft_printf("Error\n");
				exit(1);
			}
		}
		i++;
	}
}

void	err_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_duplication_caractere(char **tab)
{
	struct s_mystruct	myvar;

	myvar.exite = 0;
	myvar.collect = 0;
	myvar.player = 0;
	myvar.i = 0;
	while (tab[myvar.i])
	{
		myvar.j = 0;
		while (tab[myvar.i][myvar.j])
		{
			if (tab[myvar.i][myvar.j] == 'P')
				myvar.player++;
			else if (tab[myvar.i][myvar.j] == 'E')
				myvar.exite++;
			else if (tab[myvar.i][myvar.j] == 'C')
				myvar.collect++;
			myvar.j++;
		}
		myvar.i++;
	}
	if (myvar.player != 1 || myvar.exite != 1 || myvar.collect <= 0)
		err_exit();
	return (myvar.collect);
}

void	ft_check_if_rectangle(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (i == 0)
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
	ft_check_if_rectangle_finalline(tab);
	ft_check_1er_clone(tab);
}

int	check_map(char **tab)
{
	int	n_collect;

	if (!tab)
	{
		ft_printf("error\n");
		exit(1);
	}
	ft_check_caractere(tab);
	ft_check_if_rectangle(tab);
	n_collect = ft_duplication_caractere(tab);
	return (n_collect);
}
