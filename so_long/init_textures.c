/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:48:19 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:04:56 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	long_if(t_game *game, int y, int x)
{
	if (game->map[y][x] == '2')
	{
		mlx_image_to_window(game->mlx, game->enemy, x * 64, y * 64);
		game->e++;
	}
	if (game->map[y][x] == 'P')
	{
		mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
		g_img = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/golem.png"));
		mlx_image_to_window(game->mlx, g_img, x * 64, y * 64);
		game->x_pos = x;
		game->y_pos = y;
		game->nb_p++;
	}
	if (game->map[y][x] != 'P' &&
		game->map[y][x] != '2' && game->map[y][x] != '0' &&
		game->map[y][x] != '1' && game->map[y][x] != 'C' &&
		game->map[y][x] != 'E' &&
		game->map[y][x] != 'c' && game->map[y][x] != '\n')
	{
		printf("map incorrect\n");
		mlx_close_window(game->mlx);
	}
}

void	reinit_textures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->e = 0;
	game->enemy = mlx_texture_to_image(game->mlx,
			mlx_load_png("imgs/enemy.png"));
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			long_if(game, y, x);
			x++;
		}
		y++;
	}
}

void	ft_comparaison(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->box, x * 64, y * 64);
	if (game->map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
		mlx_image_to_window(game->mlx, game->croquette_grass,
			x * 64, y * 64);
		game->c++;
	}
	if (game->map[y][x] == '2')
	{
		mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
		game->e++;
	}
	if (game->map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit, x * 64, y * 64);
		game->nb_e++;
	}
}

void	ft_check_map(t_game *game, int y, int x)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_comparaison(game, y, x);
			x++;
		}	
		y++;
	}
}

void	init_textures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	game->c = 0;
	game->e = 0;
	game->nb_e = 0;
	game->mov = ft_itoa(game->d);
	game->exit = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/exit.png"));
	game->grass = mlx_texture_to_image(game->mlx,
			mlx_load_png("imgs/grass_test.png"));
	game->box = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/box.png"));
	game->croquette_grass = mlx_texture_to_image(game->mlx,
			mlx_load_png("imgs/croquette.png"));
	game->enemy = mlx_texture_to_image(game->mlx,
			mlx_load_png("imgs/enemy.png"));
	ft_check_map(game, y, x);
	reinit_textures(game);
	game->mouvement = mlx_put_string(game->mlx, game->mov, 0, 0);
}
