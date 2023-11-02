/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:39:55 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:39:57 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player_angle -= 0.08;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player_angle += 0.08;
}
