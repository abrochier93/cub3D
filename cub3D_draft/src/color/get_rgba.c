/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:43:19 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 08:39:44 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	get_rgba(int r, int g, int b, int a)
{
	unsigned int	color;

	color = 0;
	color |= r << 24;
	color |= g << 16;
	color |= b << 8;
	color |= a;
	return (color);
}
