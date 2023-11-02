/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:43:26 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 17:32:34 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_colors_tab(char *str)
{
	int	i;
	int	tab_length;
	int	whitespace_count;
	int	alpha_count;

	tab_length = ft_strlen(str);
	whitespace_count = 0;
	alpha_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 33 && str[i] <= 47)
			alpha_count++;
		if (str[i] >= 58 && str[i] < 127)
			alpha_count++;
		if (str[i] == ' ' || str[i] == '\t')
			whitespace_count++;
		i++;
	}
	if (alpha_count > 0 || whitespace_count == tab_length)
	{
		str[0] = '+';
		return (1);
	}
	return (0);
}

bool	is_not_numeric(char **colors)
{
	int	j;
	int	flag;

	j = 0;
	while (j <= 2)
	{
		flag = ft_check_colors_tab(colors[j]);
		j++;
	}
	if (flag == 1)
		return (true);
	return (false);
}

bool	load_color(unsigned int *c, char *line)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	colors = ft_split(line, ',');
	if (!colors)
		return (false);
	if (ft_arraylen(colors) < 3 || is_not_numeric(colors) == true)
	{
		ft_msg_err(ERR_RGB_NUMERIC);
		free_map(colors);
		return (false);
	}
	r = atoi(colors[0]);
	g = atoi(colors[1]);
	b = atoi(colors[2]);
	if (r < 0 || g < 0 || b < 0)
	{
		ft_msg_err(ERR_COLOR_FORMAT);
		return (false);
	}
	*c = get_rgba(r, g, b, 255);
	free_map(colors);
	return (true);
}
