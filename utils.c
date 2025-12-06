/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:38:32 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/06 16:56:10 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map, game->map_h);
	exit(0);
	return (0);
}

void	error_exit(char *msg, t_game *game)
{
	ft_printf("%s\n", msg);
	if (game)
		close_game(game);
	exit(1);
}
