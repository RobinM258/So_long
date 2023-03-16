/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:09 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:08:58 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	map_height(void)
{
	int	fd;
	int	y;

	y = 0;
	fd = open("maps/test.ber", O_RDONLY);
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
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
	while (tmp)
	{
		game->map[i++] = tmp;
		if ((int) ft_strlen(tmp) != game->x_size)
			exit(EXIT_FAILURE);
		tmp = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void	init_map_fluid(t_game *game)
{
	int		fd;
	char	*tmp;
	int		i;	

	fd = open("maps/test.ber", O_RDONLY);
	i = 0;
	game->fluid = malloc((game->y_size + 1) * sizeof (char *));
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->fluid[i++] = tmp;
		tmp = get_next_line(fd);
	}
	game->fluid[i] = NULL;
	close(fd);
}
