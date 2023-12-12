/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:53:32 by abkhairi          #+#    #+#             */
/*   Updated: 2023/09/27 13:41:53 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_player(t_data *data)
{
	if (data->tab[data->yp][data->xp + 1] == '0')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp][data->xp + 1] = 'P';
	}
	else if (data->tab[data->yp][data->xp + 1] == 'C')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp][data->xp + 1] = 'P';
		data->collect_nmbr--;
	}
	else if (data->tab[data->yp][data->xp + 1] == 'E' 
		&& data->collect_nmbr == 0)
	{
		data->tab[data->yp][data->xp] = '0';
		exit(0);
	}
	if (data->tab[data->yp][data->xp + 1] != '1')
		data->moves++;
	ft_draw_map(data);
}

void	left_player(t_data *data)
{
	if (data->tab[data->yp][data->xp - 1] == '0')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp][data->xp - 1] = 'P';
	}
	else if (data->tab[data->yp][data->xp - 1] == 'C')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp][data->xp - 1] = 'P';
		data->collect_nmbr--;
	}
	else if (data->tab[data->yp][data->xp - 1] == 'E' 
		&& data->collect_nmbr == 0)
	{
		data->tab[data->yp][data->xp] = '0';
		exit(0);
	}
	if (data->tab[data->yp][data->xp - 1] != '1')
		data->moves++; 
	ft_draw_map(data);
}

void	down_player(t_data *data)
{
	if (data->tab[data->yp +1][data->xp] == '0')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp +1][data->xp] = 'P';
	}
	else if (data->tab[data->yp +1][data->xp] == 'C')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp +1][data->xp] = 'P';
		data->collect_nmbr--;
	}
	else if (data->tab[data->yp +1][data->xp] == 'E' 
		&& data->collect_nmbr == 0)
	{
		data->tab[data->yp][data->xp] = '0';
		exit(0);
	}
	if (data->tab[data->yp + 1][data->xp] != '1')
		data->moves++; 
	ft_draw_map(data);
}

void	up_player(t_data *data)
{
	if (data->tab[data->yp -1][data->xp] == '0')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp -1][data->xp] = 'P';
	}
	else if (data->tab[data->yp -1][data->xp] == 'C')
	{
		data->tab[data->yp][data->xp] = '0';
		data->tab[data->yp -1][data->xp] = 'P';
		data->collect_nmbr--;
	}
	else if (data->tab[data->yp -1][data->xp] == 'E' 
		&& data->collect_nmbr == 0)
	{
		data->tab[data->yp][data->xp] = '0';
		exit(0);
	}
	if (data->tab[data->yp - 1][data->xp] != '1')
		data->moves++; 
	ft_draw_map(data);
}

int	move(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 124 || keycode == 2)
		right_player(data);
	else if (keycode == 126 || keycode == 13)
		up_player(data);
	else if (keycode == 125 || keycode == 1)
		down_player(data);
	else if (keycode == 123 || keycode == 0)
		left_player(data);
	ft_printf("Moves: %d\n", data->moves);
	return (0);
}
