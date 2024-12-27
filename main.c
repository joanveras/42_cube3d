/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:17 by jveras            #+#    #+#             */
/*   Updated: 2024/12/27 16:35:35 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 1)
		return (1);
	x11_connect(&program);

	program.map = open_map(argv[1]);

	

	mlx_key_hook(program.mlx_win, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, ON_DESTROY, 0L, safe_exit, &program);
	
	mlx_loop(program.mlx);

	return (0);
}
