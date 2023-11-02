/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:40 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 15:48:07 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_game(t_cub *cub)
{
	free_map_line(cub->map->lines_list);
	free_map(cub->map->map);
	free_map(cub->map->settings);
	mlx_delete_texture(cub->map->east);
	mlx_delete_texture(cub->map->north);
	mlx_delete_texture(cub->map->south);
	mlx_delete_texture(cub->map->west);
	if (cub->map)
		free(cub->map);
	if (cub)
		free(cub);
}
