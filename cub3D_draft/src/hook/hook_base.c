/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:26 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/20 17:17:05 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_base(void *param)
{
	int32_t	i;
	int32_t	j;
	t_cub	*cub;

	cub = (t_cub *)param;
	i = 0;
	while (i < cub->mlx->width)
	{
		j = 0;
		while (j < cub->mlx->height)
		{
			if (j < cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, cub->map->ceiling);
			else if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, cub->map->floor);
			j++;
		}
		i++;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}
