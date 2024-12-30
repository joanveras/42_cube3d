/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:17 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 01:24:34 by jveras           ###   ########.fr       */
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

	program.image.img = mlx_new_image(
		program.mlx,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);
	program.image.data = mlx_get_data_addr(
		program.image.img,
		&program.image.bpp,
		&program.image.size_line,
		&program.image.endian
	);

	program.texture.tex = mlx_xpm_file_to_image(
		program.mlx,
		"assets/textures/redbrick.xpm",
		&program.texture.width,
		&program.texture.height
	);
	program.texture.data = mlx_get_data_addr(
		program.texture.tex,
		&program.texture.bpp,
		&program.texture.size_line,
		&program.texture.endian
	);

	program.player.x = 19;
	program.player.y = 20;
	program.player.viewDirX = -1;
	program.player.viewDirY = 0;
	program.raycast.camera.planeX = 0;
	program.raycast.camera.planeY = 0.66;
	
	mlx_hook(program.mlx_win, ON_KEYDOWN, KeyRelease, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, ON_DESTROY, 0L, safe_exit, &program);

	mlx_loop_hook(program.mlx, raycasting, &program);
	
	mlx_loop(program.mlx);

	return (0);
}
