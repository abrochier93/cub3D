/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:28:32 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 14:00:36 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		if (!parsing(cub, argv[1]))
			ft_msg_err(ERR_MAP);
		init_game(cub);
		mlx_loop_hook(cub->mlx, &hook_base, cub);
		mlx_loop_hook(cub->mlx, &hook_player, cub);
		mlx_loop_hook(cub->mlx, &hook_color, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		free_game(cub);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err(ERR_ARG);
}
