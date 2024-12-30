/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 01:17:56 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int get_texel_color(t_texture_data *tex, int texX, int texY)
{
	char *dst = tex->data + (texY * tex->size_line + texX * (tex->bpp / 8));
	return *(unsigned int *)dst;
}
