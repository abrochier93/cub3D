/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:39:38 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:24:47 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	adjust(t_cub *cub, float dx, float dy, unsigned char flag)
{
	dx *= 12;
	dy *= 12;
	if (flag == '+')
	{
		if (!is_wall(cub, cub->coord[X] + cub->distance_x * 32,
				cub->coord[Y] + cub->distance_y * 32))
		{
			cub->coord[X] += dx;
			cub->coord[Y] += dy;
			cub->deltat += dx;
		}
	}
	if (flag == '-')
	{
		if (!is_wall(cub, cub->coord[X] - cub->distance_x * 32,
				cub->coord[Y] - cub->distance_y * 32))
		{
			cub->coord[X] -= dx;
			cub->coord[Y] -= dy;
			cub->deltat -= dx;
		}
	}
}
