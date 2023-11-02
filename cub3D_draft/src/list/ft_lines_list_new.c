/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_list_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:40:19 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:40:22 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_lines_list	*ft_lines_list_new(char *line)
{
	t_lines_list	*lines_list;

	lines_list = malloc(sizeof(t_lines_list));
	if (!lines_list)
		return (NULL);
	lines_list->line = line;
	lines_list->next = NULL;
	lines_list->prev = NULL;
	return (lines_list);
}
