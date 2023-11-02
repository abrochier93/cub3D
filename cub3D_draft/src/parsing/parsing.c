/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:36:31 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 17:36:10 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	parsing(t_cub *cub, char *file)
{
	int	fd;

	if (!ft_file_access(file, ".cub"))
		return (ft_msg_err(ERR_FILE_FOUND));
	fd = open(file, O_RDONLY);
	if (!store_map(cub, fd))
		ft_msg_err_close(ERR_MAP, &fd);
	if (cub->map->height > 33 || cub->map->width > 101)
		ft_msg_err_close(ERR_BIG_MAP, &fd);
	if (cub->map->height <= 3 || cub->map->width <= 3)
		ft_msg_err_close(ERR_SMALL_MAP, &fd);
	close(fd);
	if (!map_is_valid(cub))
		return (false);
	cub->map->map = ft_list_to_array(cub);
	if (!cub->map->map)
		return (false);
	if (!map_correction(cub) || !is_playable(cub))
		return (false);
	if ((int)ft_strlen(cub->map->map[cub->map->height - 2])
		- (int)ft_strlen(cub->map->map[cub->map->height - 3]) <= -2)
		return (ft_msg_err(ERR_FEW_CHAR));
	return (true);
}
