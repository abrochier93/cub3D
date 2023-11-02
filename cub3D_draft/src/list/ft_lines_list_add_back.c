/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_list_add_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:40:14 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:40:17 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_lines_list_add_back(t_lines_list **lines_list, char *line)
{
	t_lines_list	*new;
	t_lines_list	*last;

	new = ft_lines_list_new(line);
	last = ft_last_lines_list(*lines_list);
	if (!last->line)
	{
		(*lines_list) = new;
		free(last);
		(*lines_list)->place++;
	}
	else
	{
		last->next = new;
		new->prev = last;
		(*lines_list)->place++;
	}
}
