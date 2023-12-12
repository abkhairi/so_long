/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:11:47 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/04 12:54:40 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errer(void)
{
	printf("Error map incorrect\n");
	exit(1);
}

static char	*free_s1_join(char *s1, char *s2)
{
	char	*s;

	if (!s1)
		s1 = ft_strdup("");
	s = ft_strjoin(s1, s2);
	free(s1);
	return (s);
}

char	**read_map(char *path)
{
	int		fd;
	char	*join;
	char	*line;
	char	**tab;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		errer();
	line = get_next_line(fd);
	if (line == NULL || *line == '\n')
		errer();
	join = NULL;
	while (line)
	{
		ft_check_rect(line);
		join = free_s1_join(join, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	tab = ft_split(join, '\n');
	free(join);
	close(fd);
	return (tab);
}
