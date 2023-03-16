/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:41:56 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 14:56:57 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_deplacement(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (i <= game->e - 1)
	{	
		n =(rand() % (7));
		if (n == 1 && game->map[game->enemy->instances[i].y / 64 + 1][game->enemy->instances[i].x / 64] != '1')
			game->enemy->instances[i].y += 64;
		if (n == 2 && game->map[game->enemy->instances[i].y / 64 - 1][game->enemy->instances[i].x / 64] != '1')
			game->enemy->instances[i].y -= 64;
		if (n == 3 && game->map[game->enemy->instances[i].y / 64][game->enemy->instances[i].x / 64 + 1] != '1')
			game->enemy->instances[i].x += 64;
		if (n == 4 && game->map[game->enemy->instances[i].y / 64][game->enemy->instances[i].x / 64 - 1] != '1')
			game->enemy->instances[i].x -= 64;
		i++;
	}
}

void	ft_touch_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->e - 1)
	{
		if (game->enemy->instances[i].x / 64 == game->x_pos
			&& game->enemy->instances[i].y / 64 == game->y_pos
			&& game->enemy->instances[i].enabled == 1)
		{
			printf("Perdu");
			mlx_close_window(game->mlx);
		}
		i++;
	}
}
