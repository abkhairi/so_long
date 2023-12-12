/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:03:00 by abkhairi          #+#    #+#             */
/*   Updated: 2023/09/27 11:14:44 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libftpush/libft.h"
# include "get_next_line/get_next_line.h"
# include "finalprintf/ft_printf.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**tab;
	void	*player;
	void	*exite;
	void	*space;
	void	*collect;
	void	*wall;
	char	**new_map;
	int		xp;
	int		yp;
	int		collect_nmbr;
	int		moves;
}	t_data;

struct s_mystruct{
	int	i;
	int	j;
	int	player;
	int	exite;
	int	collect;
};

char	**read_map(char *path);
void	ft_check_extension_map(char *av1);
void	ft_check_if_rectangle(char **tab);
void	ft_check_extension_map(char *av1);
int		ft_strlen_pro(char *str);
void	ft_check_rect(char *line);
int		ft_tabsize(char **tab);
void	ft_check_if_rectangle_finalline(char **tab);
void	ft_check_1er_clone(char **tab);
char	**ft_create_new_map(char **tab);
int		*ft_position_p(char **tab);
void	ft_floodfill(char **tab, int x, int y);
void	ft_check_validpath(char **tab);
void	initialize_xpms(t_data *data);
void	ft_draw_map(t_data *data);
int		position_player_y(t_data data);
void	right_player(t_data *data);
int		move(int keycode, t_data *data);
int		check_map(char **tab);
void	ft_position(t_data *data);

#endif