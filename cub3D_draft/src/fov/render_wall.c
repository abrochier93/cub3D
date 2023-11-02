/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:42:50 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/30 14:42:25 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	render_wall(t_cub *cub, float angle, int pos_x)
{
	int		i;
	float	x;
	float	y;
	float	wall[2];

	i = 1;
	cub->ray_x = cos((angle));
	cub->ray_y = -sin((angle));
	while (1)
	{
		x = cub->coord[X] + cub->ray_x * i;
		y = cub->coord[Y] + cub->ray_y * i;
		if (is_wall(cub, x, y))
		{
			wall[X] = x;
			wall[Y] = y;
			cub->texture = get_texture(cub, wall);
			draw_wall(cub, wall, pos_x, angle);
			return (false);
		}
		i++;
	}
	return (true);
}
