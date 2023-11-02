/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:43:05 by abrochie          #+#    #+#             */
/*   Updated: 2023/10/31 14:10:52 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_msg_err(char *error)
{
	write(2, "Error\n", 7);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	return (0);
}
