/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:02:13 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 15:27:18 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_utils(t_game *game)
{
	ft_colectible(game);
	ft_touch_enemy(game);
	ft_deplacement(game);
	ft_touch_enemy(game);
	ft_exit(game);
	game->mouvement->instances[0].enabled = 0;
	game->mov = ft_itoa(game->d);
	printf("Mouvement : %d\n", game->d);
	game->mouvement = mlx_put_string(game->mlx, game->mov, 0, 0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game = param;
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& ft_colision(game, 'w') == 1)
		ft_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& ft_colision(game, 's') == 1)
		ft_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& ft_colision(game, 'a') == 1)
		ft_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& ft_colision(game, 'd') == 1)
		ft_right(game);
	if (keydata.key == MLX_KEY_SPACE)
		ft_space(game);
}
