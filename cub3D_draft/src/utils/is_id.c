/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:34:24 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:34:57 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_id(char *line, char *str)
{
	char	*tmp;

	tmp = get_path(line, str);
	if (tmp)
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}
