/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:18 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:41:19 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_msg_err(ERR_MALLOC);
	cub->map = init_map();
	cub->coord[X] = 0;
	cub->coord[Y] = 0;
	cub->distance_x = 0;
	cub->distance_y = 0;
	cub->deltat = 0;
	cub->p_dir = 0;
	return (cub);
}
