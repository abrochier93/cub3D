/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:57 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:42:01 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_settings(char **settings)
{
	int	i;

	i = 0;
	while (i < 7)
		free(settings[i++]);
	free(settings);
}
