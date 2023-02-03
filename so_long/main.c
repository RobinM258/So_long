/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:02 by romartin          #+#    #+#             */
/*   Updated: 2023/02/03 12:00:55 by romartin         ###   ########.fr       */
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
#define WIDTH 1280
#define HEIGHT 1280

mlx_image_t	*g_img;
mlx_image_t	*g_img2;

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
	game->map = malloc(game->y_size + sizeof (char *));
	tmp = get_next_line(fd);
	game->x_size = (int) ft_strlen(tmp);
	while(tmp)
	{
		game->map[i++] = tmp;
		if ((int) ft_strlen(tmp) != game->x_size)
			exit(EXIT_FAILURE);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}

void init_textures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->grass = mlx_texture_to_image(game->mlx, mlx_load_png("imgs/grass_test.png"));
	x = 0;
	while(game->map[y][x])
	{
		if (game->map[y][x] == '0')
			mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
	}
}

void	hook(mlx_key_data_t david, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W) && g_img->instances[0].y > 0)
		g_img->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_S) && g_img->instances[0].y < HEIGHT - 64)
		g_img->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_A) && g_img->instances[0].x > 0)
		g_img->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_D) && g_img->instances[0].x < WIDTH - 64)
		g_img->instances[0].x += 64;
	printf("Joueur %d %d\n", g_img->instances[0].x, g_img->instances[0].y);
}

int32_t	main(void)
{
	mlx_t	*mlx;

	t_game *game;
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	init_map_size(game);
	init_textures(game);
	g_img = mlx_texture_to_image(mlx, mlx_load_png("imgs/golem.png"));
	mlx_image_to_window(mlx, g_img, 0, 0);
	g_img2 = mlx_texture_to_image(mlx, mlx_load_png("imgs/croquette.png"));
	mlx_image_to_window(mlx, g_img2, 640, 640);
	mlx_key_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
