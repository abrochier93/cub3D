/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:36:17 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 18:33:39 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	map_is_valid(t_cub *cub)
{
	t_lines_list	*lines_list;
	int				i;

	lines_list = cub->map->lines_list;
	while (lines_list)
	{
		i = 0;
		while (lines_list->line && lines_list->line[i])
		{
			if (!is_elements_valid(cub, lines_list->line[i])
				&& !ft_iswhitespace(lines_list->line[i]))
			{
				if (cub->p_dir == 0)
					ft_msg_err(ERR_PLAYER);
				return (false);
			}
			i++;
		}
		lines_list = lines_list->next;
	}
	if (cub->p_dir == 0)
		ft_msg_err(ERR_PLAYER);
	return (true);
}
