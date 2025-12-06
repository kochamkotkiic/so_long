/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:37:10 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/06 16:27:19 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_height(char *file)
{
	int		fd;
	int		h;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		i;

	game->map_h = get_height(file);
	if (game->map_h == 0)
		error_exit("Error\nEmpty map or file error", game);
	game->map = malloc(sizeof(char *) * (game->map_h + 1));
	if (!game->map)
		error_exit("Error\nMalloc failed", game);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < game->map_h)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	game->map_w = ft_strlen(game->map[0]);
}
