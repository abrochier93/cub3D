/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_lines_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:40:00 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/18 13:40:03 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_lines_list	*ft_last_lines_list(t_lines_list *lines_list)
{
	if (!lines_list)
		return (NULL);
	while (lines_list->next)
		lines_list = lines_list->next;
	return (lines_list);
}
