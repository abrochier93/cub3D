/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_multiple_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:35:05 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:22:50 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_multiple_of(float pos, int x)
{
	int	coord;

	coord = (int)floorf(pos);
	if ((coord % x) == 0 || (coord + 1) % x == 0)
		return (true);
	return (false);
}
