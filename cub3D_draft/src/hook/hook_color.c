/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:20:31 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:20:59 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_color(void *param)
{
	t_cub		*cub;
	uint32_t	color;

	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_KP_1))
	{
		color = get_rgba(247, 202, 201, 255);
		cub->map->floor = color;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_KP_2))
		load_color(&cub->map->floor, cub->map->settings[4]);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_KP_4))
	{
		color = get_rgba(0, 0, 0, 255);
		cub->map->ceiling = color;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_KP_5))
		load_color(&cub->map->ceiling, cub->map->settings[5]);
}
