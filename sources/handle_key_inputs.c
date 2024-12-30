/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:17 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 01:30:42 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	handle_key_inputs(int keycode, t_program *program)
{
	if (keycode == ESC)
		safe_exit(program);

	if (keycode == W)
	{
		if (program->map.map[(int)(program->player.x + program->player.viewDirX * MOVE_SPEED)][(int)program->player.y] == '0')
			program->player.x += program->player.viewDirX * MOVE_SPEED;
		if (program->map.map[(int)program->player.x][(int)(program->player.y + program->player.viewDirY * MOVE_SPEED)] == '0')
			program->player.y += program->player.viewDirY * MOVE_SPEED;
	}
	if (keycode == S)
	{
		if (program->map.map[(int)(program->player.x - program->player.viewDirX * MOVE_SPEED)][(int)program->player.y] == '0')
			program->player.x -= program->player.viewDirX * MOVE_SPEED;
		if (program->map.map[(int)program->player.x][(int)(program->player.y - program->player.viewDirY * MOVE_SPEED)] == '0')
			program->player.y -= program->player.viewDirY * MOVE_SPEED;
	}
	if (keycode == D)
	{
		double oldDirX = program->player.viewDirX;
		program->player.viewDirX = program->player.viewDirX * cos(-ROT_SPEED) - program->player.viewDirY * sin(-ROT_SPEED);
		program->player.viewDirY = oldDirX * sin(-ROT_SPEED) + program->player.viewDirY * cos(-ROT_SPEED);
		double oldPlaneX = program->raycast.camera.planeX;
		program->raycast.camera.planeX = program->raycast.camera.planeX * cos(-ROT_SPEED) - program->raycast.camera.planeY * sin(-ROT_SPEED);
		program->raycast.camera.planeY = oldPlaneX * sin(-ROT_SPEED) + program->raycast.camera.planeY * cos(-ROT_SPEED);
	}
	if (keycode == A)
	{
		double oldDirX = program->player.viewDirX;
		program->player.viewDirX = program->player.viewDirX * cos(ROT_SPEED) - program->player.viewDirY * sin(ROT_SPEED);
		program->player.viewDirY = oldDirX * sin(ROT_SPEED) + program->player.viewDirY * cos(ROT_SPEED);
		double oldPlaneX = program->raycast.camera.planeX;
		program->raycast.camera.planeX = program->raycast.camera.planeX * cos(ROT_SPEED) - program->raycast.camera.planeY * sin(ROT_SPEED);
		program->raycast.camera.planeY = oldPlaneX * sin(ROT_SPEED) + program->raycast.camera.planeY * cos(ROT_SPEED);
	}

	return (0);
}
