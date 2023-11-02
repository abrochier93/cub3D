/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_elements_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:34:03 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:34:10 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_elements_valid(t_cub *cub, char c)
{
	if ((c == '0' || c == '1') || ((c == 'N' || c == 'E' || c == 'W'
				|| c == 'S') && cub->p_dir == 0))
	{
		if (c == 'N')
			cub->p_dir = 'N';
		else if (c == 'E')
			cub->p_dir = 'E';
		else if (c == 'W')
			cub->p_dir = 'W';
		else if (c == 'S')
			cub->p_dir = 'S';
		return (true);
	}
	else
		return (false);
}
