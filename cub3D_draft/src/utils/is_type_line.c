/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:35:36 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:35:38 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_type_line(char *line)
{
	int			i;
	static int	check[1];

	i = 0;
	while (line && line[i])
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			check[0] = 1;
			return (1);
		}
		else if (ft_isalpha(line[i]) && !check[0])
			return (2);
		else
			return (3);
		i++;
	}
	return (0);
}
