/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:51:59 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/06 17:16:51 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	if (new_x < 0 || new_y < 0 || new_x >= game->map_w || new_y >= game->map_h)
		return ;
	next_tile = game->map[new_y][new_x];
	if (next_tile == '1' || (next_tile == 'E' && game->collectibles > 0))
		return ;
	if (next_tile == 'C')
		game->collectibles--;
	if (next_tile == 'E' && game->collectibles == 0)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		ft_printf("You won!!!!! Kitty can drink beer now yippee :DD\n");
		close_game(game);
	}
	if (game->map[game->p_y][game->p_x] != 'E')
		game->map[game->p_y][game->p_x] = '0';
	game->p_x = new_x;
	game->p_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == 65362)
		move_player(game, game->p_x, game->p_y - 1);
	else if (keycode == 65364)
		move_player(game, game->p_x, game->p_y + 1);
	else if (keycode == 65361)
		move_player(game, game->p_x - 1, game->p_y);
	else if (keycode == 65363)
		move_player(game, game->p_x + 1, game->p_y);
	return (0);
}
