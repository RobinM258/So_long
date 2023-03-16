/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:56 by romartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:07:33 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <memory.h>

mlx_image_t	*g_img;
t_game *game;

char	*ft_itoa(int n);
void	key_hook(mlx_key_data_t keydata, void *param);
void 	ft_up(t_game *game);
void 	ft_left(t_game *game);
void 	ft_right(t_game *game);
void 	ft_down(t_game *game);
void 	ft_space(t_game *game);
void 	ft_exit(t_game *game);
void	init_textures(t_game *game);
void	reinit_textures(t_game *game);
void	ft_deplacement(t_game *game);
void	ft_colectible(t_game *game);
void	ft_touch_enemy(t_game *game);
void	ft_utils(t_game *game);
void	ft_space(t_game *game);
void	init_map_size(t_game *game);
void	init_map_fluid(t_game *game);
void	ft_exit(t_game *game);
void	ft_colectible(t_game *game);
void	ft_deplacement(t_game *game);
void	ft_touch_enemy(t_game *game);
int		ft_fluid_filler(t_game *game, int x, int y);
int		parsing(t_game *game);
int		map_height(void);
int		ft_colision(t_game *game, int c);

#endif