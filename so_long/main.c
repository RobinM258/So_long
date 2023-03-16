/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:02 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:05:12 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int32_t	main(void)
{
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_map_size(game);
	game->nb_colectible = 0;
	game->d = 0;
	game->nb_p = 0;
	game->cro = 0;
	game->ex = 0;
	game->mlx = mlx_init(game->x_size * 64, game->y_size * 64, "MLX42", true);
	game->y_pos = 0;
	game->x_pos = 0;
	init_textures(game);
	init_map_fluid(game);
	if (parsing(game) == 1)
	{
		if (ft_fluid_filler(game, game->x_pos, game->y_pos) == 0)
		{
			mlx_close_window(game->mlx);
			printf("MAP ERROR\n");
		}
	}
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
