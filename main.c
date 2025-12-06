/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:36:54 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/06 17:19:37 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nInvalid number of arguments", NULL);
	ft_bzero(&game, sizeof(t_game));
	read_map(argv[1], &game);
	check_map_validity(&game);
	check_path(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit("Error\nMLX Init failed", &game);
	game.win = mlx_new_window(game.mlx, game.map_w * 64,
			game.map_h * 64, "Alcoholic cat");
	if (!game.win)
		error_exit("Error\nWindow creation failed", &game);
	init_graphics(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
