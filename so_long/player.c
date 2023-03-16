/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:19:12 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 14:49:30 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_colision(t_game *game, int c)
{
	if (c == 'w')
	{
		if (game->map[game->y_pos - 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 's')
	{
		if (game->map[game->y_pos + 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 'a')
	{
		if (game->map[game->y_pos][game->x_pos - 1] != '1')
			return (1);
	}
	if (c == 'd')
	{
		if (game->map[game->y_pos][game->x_pos + 1] != '1')
			return (1);
	}
	return (0);
}

void	ft_exit(t_game *game)
{
	if (game->map[game->y_pos][game->x_pos] == 'E')
	{
		if (game->nb_colectible == game->c)
		{
			printf("Gagné\n");
			mlx_close_window(game->mlx);
		}
	}
}

void	ft_colectible(t_game *game)
{
	int	i;

	game->d++;
	i = -1;
	if (game->map[game->y_pos][game->x_pos] == 'C')
	{
		while (++i < game->c)
		{
			if (game->croquette_grass->instances[i].x / 64 == game->x_pos
				&& game->croquette_grass->instances[i].y / 64 == game->y_pos)
			{
				game->croquette_grass->instances[i].enabled = 0;
				game->map[game->y_pos][game->x_pos] = 'c';
			}
		game->nb_colectible += 1;
		}
	}
}
