/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_correction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:31:22 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 17:35:48 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_char_correction(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr("NEWS", line[i]))
		{
			if (ft_strchr(" \t\n", line[i]))
				line[i] = '1';
			if (i == (int)(ft_strlen(line) - 1) && line[i] != '1')
				line[i] = '1';
		}
		i++;
	}
	return (line);
}
