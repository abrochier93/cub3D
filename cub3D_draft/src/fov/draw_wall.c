/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:42:04 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:29:19 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	init_distance(t_cub *cub, float wall[2], float angle)
{
	float	distance;

	distance = sqrtf(powf(wall[X] - cub->coord[X], 2) + powf(wall[Y]
				- cub->coord[Y], 2));
	distance = (distance * cosf(angle - cub->player_angle + 0.05));
	distance = roundf(cub->map->square_size * (HEIGHT / distance));
	if (distance > HEIGHT)
		distance = HEIGHT;
	return (distance);
}

void	draw_wall(t_cub *cub, float wall[2], int pos_x, float angle)
{
	float		distance;
	float		coef_y;
	float		j;
	float		j_min;
	uint32_t	color;

	distance = init_distance(cub, wall, angle);
	coef_y = (distance / 64);
	j = (HEIGHT * 0.5 - (distance * 0.5));
	j_min = round(j / coef_y);
	while (j < (HEIGHT * 0.5) + distance * 0.5)
	{
		if (cub->texture)
			color = get_pixels(cub, j, coef_y, j_min);
		else
			color = 0xF6c7a89;
		mlx_put_pixel(cub->win, pos_x, j, color);
		j++;
	}
}
