/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:18:15 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:19:31 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	free_map(t_map *map)
{
	if (map->map != NULL)
	{
		for (int i = 0; map->map[i] != NULL; i++)
		{
			free(map->map[i]);
		}
		free(map->map);
		map->map = NULL;
	}
}
