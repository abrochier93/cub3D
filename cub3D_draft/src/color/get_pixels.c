/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:43:12 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 13:28:43 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_pixel_y(int j, float coef_y, int j_min)
{
	int		j_bis;
	int		pixel_y;

	j_bis = round(j / coef_y);
	pixel_y = j_bis - j_min - 1;
	if (pixel_y <= 0)
		pixel_y = 0;
	return (pixel_y);
}

uint32_t	get_pixels(t_cub *cub, int j, float coef_y, int j_min)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = (int)cub->way_wall % 64;
	pixel_y = init_pixel_y(j, coef_y, j_min);
	return ((((uint32_t *)cub->texture->pixels)
			[(pixel_y * cub->texture->width + pixel_x)]));
}
