/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:42:55 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:42:56 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_way(t_cub *cub, float way)
{
	cub->way_wall = way;
}

mlx_texture_t	*get_texture(t_cub *cub, float wall[2])
{
	int	on_x;
	int	on_y;

	on_x = is_multiple_of(wall[X], cub->map->square_size);
	on_y = is_multiple_of(wall[Y], cub->map->square_size);
	if (cub->coord[X] > wall[X] && (on_x && !on_y))
		return (get_way(cub, wall[Y]), cub->map->west);
	else if (cub->coord[Y] < wall[Y] && (!on_x && on_y))
		return (get_way(cub, wall[X]), cub->map->south);
	else if (cub->coord[X] < wall[X] && (on_x && !on_y))
		return (get_way(cub, wall[Y]), cub->map->east);
	else if (cub->coord[Y] > wall[Y] && (!on_x && on_y))
		return (get_way(cub, wall[X]), cub->map->north);
	return (NULL);
}
