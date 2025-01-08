/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:17 by jveras            #+#    #+#             */
/*   Updated: 2025/01/08 09:29:52 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 1)
		return (1);

	x11_connect(&program);

	program.map.map = open_map(argv[1]);

	load_img(program.mlx, &program.main_image, WINDOW_WIDTH, WINDOW_HEIGHT);
	load_img_data(&program.main_image);

	load_texture(program.mlx, &program.wall_texture, "assets/textures/redbrick.xpm");
	load_texture_data(&program.wall_texture);

	load_game_and_raycast_initial_info(&program);
	
	mlx_hook(program.mlx_win, ON_KEYDOWN, KeyRelease, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, ON_DESTROY, NoEventMask, safe_exit, &program);

	mlx_loop_hook(program.mlx, wall_casting, &program);
	
	mlx_loop(program.mlx);

	return (0);
}
