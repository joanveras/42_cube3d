/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:13:19 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"
#include "../../../includes/structs.h"

void	left(t_program *p, int key)
{
	double	old_dir;
	double	old_plane;

	if (key != 'a' && key != 'A' && key != 65361)
		return ;
	old_dir = p->player.view_dir_x;
	p->player.view_dir_x = old_dir * cos(-ROT_SPEED)
		- p->player.view_dir_y * sin(-ROT_SPEED);
	p->player.view_dir_y = old_dir * sin(-ROT_SPEED)
		+ p->player.view_dir_y * cos(-ROT_SPEED);
	old_plane = p->raycast.camera.plane_x;
	p->raycast.camera.plane_x = old_plane * cos(-ROT_SPEED)
		- p->raycast.camera.plane_y * sin(-ROT_SPEED);
	p->raycast.camera.plane_y = old_plane * sin(-ROT_SPEED)
		+ p->raycast.camera.plane_y * cos(-ROT_SPEED);
}
