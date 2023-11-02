/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:40:26 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 13:29:09 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**ft_list_to_array(t_cub *cub)
{
	t_lines_list	*lines_list;
	char			**map;
	int				i;

	i = 0;
	map = ft_calloc(cub->map->height, sizeof(char *));
	if (!map)
		return (NULL);
	lines_list = cub->map->lines_list;
	while (lines_list)
	{
		map[i] = ft_strdup(lines_list->line);
		lines_list = lines_list->next;
		i++;
	}
	return (map);
}
