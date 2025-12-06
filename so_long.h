/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:36:44 by emurbane          #+#    #+#             */
/*   Updated: 2025/12/06 17:21:21 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

/* Klawisze (dla Linux/Mac mogą się różnić, sprawdź kody) */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		map_w;
	int		map_h;
	char	**map;
	int		p_x;
	int		p_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

/* Funkcje z map_check.c */
void	check_map_validity(t_game *game);

/* Funkcje z map_parsing.c */
void	read_map(char *file, t_game *game);

/* Funkcje z graphics.c */
void	init_graphics(t_game *game);
void	render_map(t_game *game);

/* Funkcje z events.c */
int		key_hook(int keycode, t_game *game);

/* Funkcje z utils.c */
int		close_game(t_game *game);
void	error_exit(char *msg, t_game *game);
void	free_map(char **map, int height); /* <--- Tego brakowało! */

/* Funkcje z flood_fill.c */
void	check_path(t_game *game);

#endif
