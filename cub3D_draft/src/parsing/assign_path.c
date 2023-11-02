/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:35:55 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:35:56 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	assign_path(t_map *map, char *line)
{
	if (is_id(line, "NO"))
		map->settings[0] = get_path(line, "NO");
	if (is_id(line, "SO"))
		map->settings[1] = get_path(line, "SO");
	if (is_id(line, "WE"))
		map->settings[2] = get_path(line, "WE");
	if (is_id(line, "EA"))
		map->settings[3] = get_path(line, "EA");
	if (is_id(line, "F"))
		map->settings[4] = get_path(line, "F");
	if (is_id(line, "C"))
		map->settings[5] = get_path(line, "C");
}
