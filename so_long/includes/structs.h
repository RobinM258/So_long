/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:16:41 by romartin          #+#    #+#             */
/*   Updated: 2023/02/03 12:01:51 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	int			x_pos;
	int			y_pos;

} t_player;

typedef struct s_game
{
	t_player	*steve;
	mlx_t		*mlx;
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	char		**map;
	int			y_size;
	int			x_size;
} t_game;

#endif