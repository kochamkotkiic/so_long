/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:37:43 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/05 16:37:45 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_h)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_w)
			error_exit("Error\nMap is not rectangular", game);
		if (game->map[i][0] != '1' || game->map[i][game->map_w - 1] != '1')
			error_exit("Error\nMap not enclosed by walls", game);
		i++;
	}
	i = 0;
	while (i < game->map_w)
	{
		if (game->map[0][i] != '1' || game->map[game->map_h - 1][i] != '1')
			error_exit("Error\nMap not enclosed by walls", game);
		i++;
	}
}

static void	count_elements(t_game *game, int *e, int *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_h)
	{
		x = -1;
		while (++x < game->map_w)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			else if (game->map[y][x] == 'E')
				(*e)++;
			else if (game->map[y][x] == 'P')
			{
				(*p)++;
				game->p_x = x;
				game->p_y = y;
			}
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				error_exit("Error\nInvalid character in map", game);
		}
	}
}

void	check_map_validity(t_game *game)
{
	int	exit_count;
	int	player_count;

	exit_count = 0;
	player_count = 0;
	check_walls(game);
	count_elements(game, &exit_count, &player_count);
	if (game->collectibles == 0)
		error_exit("Error\nNo collectibles (Mice) on map", game);
	if (exit_count != 1)
		error_exit("Error\nMap must have exactly one Exit", game);
	if (player_count != 1)
		error_exit("Error\nMap must have exactly one Start (Cat)", game);
}
