/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:06:26 by abkhairi          #+#    #+#             */
/*   Updated: 2023/09/26 19:33:51 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_position_p(char **tab)
{
	int	x;
	int	y;
	int	*xy;

	xy = (int *)ft_calloc(2, sizeof(int));
	if (!xy)
		return (NULL);
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
			{
				xy[0] = x;
				xy[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (xy);
}

char	**ft_create_new_map(char **tab)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc((ft_tabsize((char **)tab) + 1) * sizeof(char *));
	if (!new_map)
	{
		ft_printf("allocation of the new map is failed\n");
		return (NULL);
	}
	while (tab[i])
	{
		new_map[i] = ft_strdup(tab[i]);
		if (!new_map[i])
		{
			ft_printf("allocation of the new map is failed\n");
			exit(1);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	ft_floodfill(char **tab, int x, int y)
{
	int	heightmap;

	heightmap = ft_tabsize(tab);
	if (x < 0 || x >= ft_strlen_pro(tab[0]) || y < 0
		|| y >= heightmap || tab[y][x] == '1'
		|| tab[y][x] == 'V' || tab[y][x] == 'E')
		return ;
	if (tab[y][x] != 'P')
		tab[y][x] = 'V';
	ft_floodfill(tab, x - 1, y);
	ft_floodfill(tab, x + 1, y);
	ft_floodfill(tab, x, y - 1);
	ft_floodfill(tab, x, y + 1);
}

void	ft_check_validpath(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
			{
				ft_printf("Error valid path!\n");
				exit(1);
			}
			if (tab[i][j] == 'E' && tab[i - 1][j] != 'V'
			&& tab[i + 1][j] != 'V' && tab[i][j - 1] != 'V'
			&& tab[i][j + 1] != 'V')
			{
				ft_printf("Error valid path!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
