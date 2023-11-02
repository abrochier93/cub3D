/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:40:50 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:30:42 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_msg_err(ERR_MALLOC);
	map->ceiling = 0;
	map->floor = 0;
	map->settings_nbr = 0;
	map->settings = ft_calloc(7, sizeof(char *));
	if (!map->settings)
		ft_msg_err(ERR_MALLOC);
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->map = NULL;
	map->height = 1;
	map->width = 0;
	map->lines_list = init_lines_list();
	return (map);
}
