/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:30 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:41:34 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_player(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	moves(cub);
	rotate(cub);
	render_fov(cub);
}
