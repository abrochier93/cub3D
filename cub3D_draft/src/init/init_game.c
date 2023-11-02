/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:05 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:30:15 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!cub->mlx)
		exit(EXIT_FAILURE);
	cub->map->square_size = 64;
	cub->fov = M_PI / 3;
	get_player_angle(cub);
	cub->coord[X] = cub->coord[X] * cub->map->square_size
		+ cub->map->square_size / 2;
	cub->coord[Y] = cub->coord[Y] * cub->map->square_size
		+ cub->map->square_size / 2;
	cub->win = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
}
