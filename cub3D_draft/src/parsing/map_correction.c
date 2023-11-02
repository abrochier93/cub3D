/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:36:14 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 13:44:13 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	map_correction(t_cub *cub)
{
	int	i;

	if (!cub->map->map)
		return (false);
	i = 0;
	while (i < cub->map->height)
	{
		cub->map->map[i] = ft_char_correction(cub->map->map[i]);
		i++;
	}
	return (true);
}
