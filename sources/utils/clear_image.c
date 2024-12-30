/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:18:46 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 01:19:05 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void clear_image(t_img_data *img, int color)
{
	int x, y;

	for (y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (x = 0; x < WINDOW_WIDTH; x++)
		{
			put_pixel(img, x, y, color);
		}
	}
}
