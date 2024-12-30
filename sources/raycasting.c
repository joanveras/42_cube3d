/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:26:48 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 01:20:33 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/cube3d.h"

int	raycasting(t_program *program)
{
	int		x;

	clear_image(&program->image, 0x000000);
	
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		program->raycast.camera.x = 2 * x / (double)WINDOW_WIDTH - 1;
		program->raycast.rayDirX = program->player.viewDirX + program->raycast.camera.planeX * program->raycast.camera.x;
		program->raycast.rayDirY = program->player.viewDirY + program->raycast.camera.planeY * program->raycast.camera.x;

		program->map.x = (int)program->player.x;
		program->map.y = (int)program->player.y;

		program->raycast.deltaDistX = fabs(1 / program->raycast.rayDirX);
		program->raycast.deltaDistY = fabs(1 / program->raycast.rayDirY);

		if (program->raycast.rayDirX < 0)
		{
			program->map.step.x = -1;
			program->raycast.sideDistX = (program->player.x - program->map.x) * program->raycast.deltaDistX;
		}
		else
		{
			program->map.step.x = 1;
			program->raycast.sideDistX = (program->map.x + 1.0 - program->player.x) * program->raycast.deltaDistX;
		}
		if (program->raycast.rayDirY < 0)
		{
			program->map.step.y = -1;
			program->raycast.sideDistY = (program->player.y - program->map.y) * program->raycast.deltaDistY;
		}
		else
		{
			program->map.step.y = 1;
			program->raycast.sideDistY = (program->map.y + 1.0 - program->player.y) * program->raycast.deltaDistY;
		}

		int side;

		while (1)
		{
			if (program->raycast.sideDistX < program->raycast.sideDistY)
			{
				program->raycast.sideDistX += program->raycast.deltaDistX;
				program->map.x += program->map.step.x;
				side = 0;
			}
			else
			{
				program->raycast.sideDistY += program->raycast.deltaDistY;
				program->map.y += program->map.step.y;
				side = 1;
			}
			if ((program->map.map[program->map.x][program->map.y] - '0') > 0)
				break ;
		}

		if (side == 0)
			program->raycast.perpWallDist = (program->raycast.sideDistX - program->raycast.deltaDistX);
		else
			program->raycast.perpWallDist = (program->raycast.sideDistY - program->raycast.deltaDistY);

		int lineHeight = (int)(WINDOW_HEIGHT / program->raycast.perpWallDist);

		int pitch = 100;
		
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2 + pitch;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2 + pitch;
		if (drawEnd >= WINDOW_HEIGHT)
			drawEnd = WINDOW_HEIGHT - 1;

		double wallX;
		if (side == 0)
			wallX = program->player.y + program->raycast.perpWallDist * program->raycast.rayDirY;
		else
			wallX = program->player.x + program->raycast.perpWallDist * program->raycast.rayDirX;
		wallX -= floor(wallX);
		
		int texX = (int)(wallX * program->texture.width) % program->texture.width;

		int y = drawStart;
		while (y < drawEnd)
		{
			int texY = (int)((y - drawStart) * (double)program->texture.height / lineHeight);
			int color = get_texel_color(&program->texture, texX, texY);
			put_pixel(&program->image, x, y, color);
			y++;
		}
		
		x++;
	}
	
	mlx_put_image_to_window(program->mlx, program->mlx_win, program->image.img, 0, 0);

	return (0);
}
