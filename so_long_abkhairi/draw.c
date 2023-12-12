/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:43:09 by abkhairi          #+#    #+#             */
/*   Updated: 2023/09/27 13:20:12 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_i(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		img, x * 50, y * 50);
	return (0);
}

void	ft_draw_map(t_data *data)
{
	int	y;
	int	x;

	y = -1; 
	while (data->tab[++y])
	{
		x = -1;
		while (data->tab[y][++x])
		{
			if (data->tab[y][x] == '1')
				mlx_i(data, data->wall, x, y);
			else if (data->tab[y][x] == '0')
				mlx_i(data, data->space, x, y);
			else if (data->tab[y][x] == 'E')
				mlx_i(data, data->exite, x, y);
			else if (data->tab[y][x] == 'C')
				mlx_i(data, data->collect, x, y);
			else if (data->tab[y][x] == 'P')
			{
				data->xp = x;
				data->yp = y;
				mlx_i(data, data->player, x, y);
			}
		}
	}
}

void	initialize_xpms(t_data *data)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	data->moves = 0;
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/RightHarry.xpm", &w, &h);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.xpm", &w, &h);
	data->space = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/Bg.xpm", &w, &h);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/Collect.xpm", &w, &h);
	data->exite = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/Exit.xpm", &w, &h);
	if (data->player == NULL || data->exite == NULL || data->wall == NULL
		|| data->space == NULL || data->collect == NULL)
	{
		ft_printf("Permission Denied\n");
		exit(1);
	}
}
