/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:42:36 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 18:06:08 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_wall(t_cub *cub, float destx, float desty)
{
	int	x;
	int	y;

	x = (int)floorf(destx / cub->map->square_size);
	y = (int)floorf(desty / cub->map->square_size);
	return (cub->map->map[y][x] == '1');
}
