/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:31:38 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 10:55:39 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**ft_duplicate_map(char **map)
{
	int		n;
	int		i;
	char	**new_map;

	n = 0;
	while (map[n])
		n++;
	new_map = (char **)malloc((n + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}
