/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/01 02:36:51 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	main_loop(t_config *config)
{
	floor_ceil(config);
	wall(config);
	// sprite(config);
	// mlx_sync(MLX_SYNC_IMAGE_WRITABLE, config->img);
	mlx_put_image_to_window(config->mlx, config->win, config->img, 0, 0);
	// mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, config->win);
	return (0);
}

static void	start_loop(t_config *config)
{
	mlx_loop_hook(config->mlx, &main_loop, config);
	mlx_hook(config->win, KEY_PRESS, 0, &key_control, config);
	mlx_hook(config->win, MOUSE_MOTION, 0, &mouse_move, config);
	mlx_hook(config->win, RED_CROSS, 0, &game_close, 0);
	mlx_loop(config->mlx);
}

int	main(int ac, char *av[])
{
	t_config	config;
	t_sprite	tmp;

	init_config(&config);
	if (ac > 4 || ac < 2)
		error_exit();
	if (parse_config(av[1], &config) == -1)
		error_exit();
	init_ptr(&config);
	start_loop(&config);
	return (0);
}
