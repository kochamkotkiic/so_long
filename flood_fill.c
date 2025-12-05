/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:38:44 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/05 16:38:46 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Kopia mapy potrzebna, żeby flood fill nie niszczył właściwej mapy gry */
static char	**copy_map(t_game *game)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * (game->map_h + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < game->map_h)
	{
		dup[i] = ft_strdup(game->map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static void	flood_fill(char **map, int x, int y, t_game *check)
{
	if (x < 0 || y < 0 || x >= check->map_w || y >= check->map_h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		check->collectibles--; // Wykorzystuję pole collectibles jako licznik
	if (map[y][x] == 'E')
		check->moves = 1; // Flaga znalezienia wyjścia

	map[y][x] = 'F'; // Oznacz jako odwiedzone
	flood_fill(map, x + 1, y, check);
	flood_fill(map, x - 1, y, check);
	flood_fill(map, x, y + 1, check);
	flood_fill(map, x, y - 1, check);
}

void	check_path(t_game *game)
{
	char	**temp_map;
	t_game	check;

	temp_map = copy_map(game);
	if (!temp_map)
		error_exit("Error\nMalloc failed in check_path", game);

	check.collectibles = game->collectibles;
	check.map_w = game->map_w;
	check.map_h = game->map_h;
	check.moves = 0; // Używam moves jako flagi 'exit found'

	flood_fill(temp_map, game->p_x, game->p_y, &check);
	free_map(temp_map, game->map_h);

	if (check.collectibles > 0 || check.moves == 0)
		error_exit("Error\nMap path is not valid (cannot reach all items/exit)", game);
}
