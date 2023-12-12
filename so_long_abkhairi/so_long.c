/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:30:02 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/03 10:38:20 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extension_map(char *av1)
{
	int	i;
	int	c;

	i = 0;
	c = ft_strlen_pro(av1) - 1;
	if (av1[c] != 'r' || av1[c - 1] != 'e' 
		|| av1[c - 2] != 'b' || av1[c - 3] != '.')
	{
		ft_printf("extension incorrect\n");
		exit(1);
	}
}

int	exit_the_game(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	else
		exit(0);
	return (0);
}

void	ft_main2(t_data data)
{
	int	*xy;

	data.new_map = ft_create_new_map(data.tab);
	xy = ft_position_p(data.new_map);
	ft_floodfill(data.new_map, xy[0], xy[1]);
	ft_check_validpath(data.new_map);
	initialize_xpms(&data);
	ft_draw_map(&data);
	mlx_hook(data.win_ptr, 2, 0, exit_the_game, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_the_game, &data);
	mlx_hook(data.win_ptr, 2, 0, move, &data);
	mlx_loop(data.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**map;
	int		w;
	int		h;

	if (ac != 2)
	{
		ft_printf("les argument incorrect\n");
		exit(1);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	ft_check_extension_map(av[1]);
	map = read_map(av[1]);
	h = ft_tabsize(map);
	w = ft_strlen_pro(map[0]);
	data.collect_nmbr = check_map(map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, w * 50, h * 50, "Game 2d");
	if (!data.win_ptr)
		return (1);
	data.tab = map;
	ft_main2(data);
	return (0);
}
