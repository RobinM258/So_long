/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:59:06 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:06 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	parsing3(t_game *game, int j, int i)
{
	while (j > 0)
	{
		if (game->map[j][i] != '1')
		{
			printf("erreur a la coordonée %d %d\n", j, i);
			mlx_close_window(game->mlx);
			return (0);
		}
		j--;
	}
	if (game->nb_p != 1 || game->nb_e != 1 || game->c == 0)
	{
		printf("game->nb_p = %d game->nb_e = %d\n", game->nb_p, game->nb_e);
		printf("erreur nb de joueur ou de sortie ou pas de colectible");
		mlx_close_window(game->mlx);
		return (0);
	}
	return (1);
}

int	parsing2(t_game *game, int j, int i)
{
	while (j < game->y_size - 1)
	{
		if (game->map[j][i] != '1')
		{
			printf("erreur a la coordonée %d %d\n", j, i);
			mlx_close_window(game->mlx);
			return (0);
		}
		j++;
	}
	while (i > 0)
	{
		if (game->map[j][i] != '1')
		{
			printf("erreur a la coordonée %d %d\n", j, i);
			mlx_close_window(game->mlx);
			return (0);
		}
		i--;
	}
	return (1);
}

int	parsing(t_game *game)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	j = 0;
	y = game->y_pos;
	x = game->x_pos;
	while (i < game->x_size - 1)
	{
		if (game->map[j][i] != '1')
		{
			printf("erreur a la coordonée %d %d\n", j, i);
			mlx_close_window(game->mlx);
			return (0);
		}
		i++;
	}
	i--;
	if (parsing2(game, j, i) == 0)
		return (0);
	if (parsing3(game, j, i) == 0)
		return (0);
	return (1);
}

void	if_fluid(t_game *game, int x, int y)
{
	if (game->fluid[y - 1][x] != '1')
	{
		game->fluid[y][x] = '1';
		ft_fluid_filler(game, x, y - 1);
	}
	if (game->fluid[y][x + 1] != '1')
	{
		game->fluid[y][x] = '1';
		ft_fluid_filler(game, x + 1, y);
	}
	if (game->fluid[y][x - 1] != '1')
	{
		game->fluid[y][x] = '1';
		ft_fluid_filler(game, x - 1, y);
	}
}

int	ft_fluid_filler(t_game *game, int x, int y)
{
	if (game->fluid[y][x] == 'C')
	{
		game->fluid[y][x] = '1';
		game->cro++;
	}
	if (game->fluid[y][x] == 'E')
	{
		game->fluid[y][x] = '1';
		game->ex++;
	}
	if (game->fluid[y + 1][x] != '1')
	{
		game->fluid[y][x] = '1';
		ft_fluid_filler(game, x, y + 1);
	}
	if_fluid(game, x, y);
	if (game->cro == game->c && game->ex == 1)
		return (1);
	return (0);
}
