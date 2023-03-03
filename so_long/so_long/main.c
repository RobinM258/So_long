/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:02 by romartin          #+#    #+#             */
/*   Updated: 2023/03/03 16:29:40 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "includes/structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <memory.h>

mlx_image_t	*g_img;

int map_height(void)
{
	int	fd;
	int	y;

	y = 0;
	fd = open("maps/test.ber", O_RDONLY);
	while (get_next_line(fd))
		y++;
	close(fd);
	return(y);
}


void	init_map_size(t_game *game)
{
	int		fd;
	char	*tmp;
	int		i;	

	fd = open("maps/test.ber", O_RDONLY);
	game->y_size = map_height();
	i = 0;
	game->map = malloc((game->y_size + 1) * sizeof (char *));
	tmp = get_next_line(fd);
	game->x_size = (int) ft_strlen(tmp);
	while(tmp)
	{
		game->map[i++] = tmp;
		if ((int) ft_strlen(tmp) != game->x_size)
			exit(EXIT_FAILURE);
		tmp = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void init_textures(t_game *game)
{
	int	x;
	int	y;
	int	a;
	int	b;

	y = 0;
	a = 0;
	b = 0;
	game->c = 0;
	game->e = 0;
	game->grass = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/grass_test.png"));
	game->box = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/box.png"));
	game->croquette_grass = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/croquette_grass.png"));
	game->golem_grass = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/golem_grass.png"));
	game->enemy = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/enemy.png"));
	x = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{ 
			if (game->map[y][x] == '0' && game->map[y][x] != '\n')
				mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
			if (game->map[y][x] == '1' && game->map[y][x] != '\n')
				mlx_image_to_window(game->mlx, game->box, x * 64, y * 64);
			if (game->map[y][x] == 'C' && game->map[y][x] != '\n')
			{
				mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
				mlx_image_to_window(game->mlx, game->croquette_grass, x * 64, y * 64);
				game->c++;
			}
			if (game->map[y][x] == '3' && game->map[y][x] != '\n')
			{
				a = y;
				b = x;
			}
			if (game->map[y][x] == '2' && game->map[y][x] != '\n')
			{
				mlx_image_to_window(game->mlx, game->enemy, x * 64, y * 64);
				mlx_texture_to_image(game->mlx, mlx_load_png("imgs/enemy.png"));
				game->e++;
			}
			x++;
		}	
		y++;	
	}
	mlx_image_to_window(game->mlx, game->grass, b * 64, a * 64);
	g_img = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/golem_grass.png"));
	mlx_image_to_window(game->mlx, g_img, b * 64, a * 64);
	game->x_pos = b;
	game->y_pos = a;		
}

void ft_touch_enemy(t_game *game)
{
	int i;

	i = 0;
	printf("checking\n");
	if(game->map[game->y_pos][game->x_pos] == '2')
	{
			printf("trouvé\n");
		while(++i < game->e)
			if(game->enemy->instances[i].x / 64 == game->x_pos && game->enemy->instances[i].y / 64 == game->y_pos)
			{
					printf("tué\n");
				game->golem_grass->instances[i].enabled = 0;
			}
	}
}

void ft_colectible(t_game *game)
{
	int i;

	i = -1;
	if(game->map[game->y_pos][game->x_pos] == 'C')
	{
		while(++i < game->c)
			if(game->croquette_grass->instances[i].x / 64 == game->x_pos && game->croquette_grass->instances[i].y / 64 == game->y_pos)
			{
				game->croquette_grass->instances[i].enabled = 0;
				game->map[game->y_pos][game->x_pos] = 'c';
			}
		game->nb_colectible += 1;
	}
}

int ft_colision(t_game *game, int c)
{
	if (c == 'w')
	{
		if(game->map[game->y_pos - 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 's')
	{
		if(game->map[game->y_pos + 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 'a')
	{
		if(game->map[game->y_pos][game->x_pos - 1] != '1')
			return (1);
	}
	if (c == 'd')
	{
		if(game->map[game->y_pos][game->x_pos + 1] != '1')
			return (1);
	}
	return (0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game = param;
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && ft_colision(game, 'w') == 1)
		{
			g_img->instances[0].y -= 64;
			game->y_pos -= 1;
			ft_colectible(game);
			ft_touch_enemy(game);
		}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && ft_colision(game, 's') == 1)
		{
			g_img->instances[0].y += 64;
			game->y_pos += 1;
			ft_colectible(game);
			ft_touch_enemy(game);
		}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && ft_colision(game, 'a') == 1)
		{
			g_img->instances[0].x -= 64;
			game->x_pos -= 1;
			ft_colectible(game);
			ft_touch_enemy(game);
		}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && ft_colision(game, 'd') == 1)
		{
			g_img->instances[0].x += 64;
			game->x_pos += 1;
			ft_colectible(game);
			ft_touch_enemy(game);
		}

	//printf("Joueur %d %d (%d,%d)\n", game->x_pos , game->y_pos, game->enemy->instances[0].x / 64, game->enemy->instances[0].y / 64);
	//printf("nb colectible recup %d sur %d\n ", game->nb_colectible, game->c);
}

int32_t	main(void)
{
	t_game *game;
	

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_map_size(game);
	game->nb_colectible = 0;
	game->mlx = mlx_init(game->x_size * 64, game->y_size * 64, "MLX42", true);
	game->y_pos = 0;
	game->x_pos = 0;
	init_textures(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
