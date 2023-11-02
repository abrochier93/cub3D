/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:35:19 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 17:38:40 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_new_map(t_cub *cub, char **map)
{
	int	i;

	i = 0;
	while (i <= cub->map->height - 2)
		free(map[i++]);
	free(map);
}

bool	is_playable(t_cub *cub)
{
	size_t	pos[2];
	char	**new_map;
	bool	is_closed;

	if (!get_player_pos(cub->map->map, pos))
		return (ft_msg_err(ERR_PLAYER_POSITION));
	cub->coord[X] = pos[0];
	cub->coord[Y] = pos[1];
	new_map = ft_duplicate_map(cub->map->map);
	if (!new_map)
		return (ft_msg_err(ERR_MALLOC));
	cub->flag = 1;
	is_closed = floodfill(cub, new_map, pos[0], pos[1]);
	if (!is_closed)
	{
		free_new_map(cub, new_map);
		return (ft_msg_err(ERR_WALLS));
	}
	free(new_map);
	return (true);
}

bool	floodfill(t_cub *cub, char **new_map, int i, int j)
{
	bool	is_closed;

	if (cub->flag == 1)
	{
		if (i < 0 || j < 0 || (j > cub->map->height - 2)
			|| (j < cub->map->height - 2 && i > (int)ft_strlen(new_map[j]) - 2)
			|| (new_map[j][i] != '1' && (j == 1) && (new_map[0][i] != '1'))
			|| (new_map[j][i] != '1' && (j == cub->map->height - 3)
			&& (new_map[j + 1][i] != '1')))
			cub->flag = 0;
		else if (new_map[j][i] == '1')
			return (true);
		else if (new_map[j][i] == '0' || new_map[j][i] == 'S'
			|| new_map[j][i] == 'N' || new_map[j][i] == 'E'
			|| new_map[j][i] == 'O')
			new_map[j][i] = '1';
		is_closed = true;
		is_closed &= floodfill(cub, new_map, i - 1, j);
		is_closed &= floodfill(cub, new_map, i + 1, j);
		is_closed &= floodfill(cub, new_map, i, j - 1);
		is_closed &= floodfill(cub, new_map, i, j + 1);
	}
	else
		is_closed = false;
	return (is_closed);
}
