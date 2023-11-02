/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:41:43 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:41:48 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map_line(t_lines_list *lines_list)
{
	t_lines_list	*temp;

	while (lines_list)
	{
		temp = lines_list;
		lines_list = lines_list->next;
		free(temp->line);
		free(temp);
	}
}
