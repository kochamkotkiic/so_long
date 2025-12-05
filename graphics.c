/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:38:06 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/05 16:38:08 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
		error_exit("Error\nFailed to load textures", game);
}

static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (game->map[y][x] == '1')
				put_img(game, game->img_wall, x, y);
			else
				put_img(game, game->img_floor, x, y);
			if (game->map[y][x] == 'C')
				put_img(game, game->img_collect, x, y);
			if (game->map[y][x] == 'E')
				put_img(game, game->img_exit, x, y);
			if (game->map[y][x] == 'P')
				put_img(game, game->img_player, x, y);
			x++;
		}
		y++;
	}
}
