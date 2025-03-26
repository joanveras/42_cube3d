/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:53:34 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:14:14 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

static void	free_tmp(int *tmp)
{
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL; // Avoid dangling pointer
	}
}

void	validate_map(t_program *program)
{

	int		i;
	int		*tmp;
	char	*str;
	
	i = 0;
	check_directions(program, &i);

	tmp = check_colors(program, program->map.map, &i);
	program->f_c_colors.floor_color = rgb_to_int(tmp);
	free_tmp(tmp);

	tmp = check_colors(program, program->map.map, &i);
	program->f_c_colors.ceiling_color = rgb_to_int(tmp);
	free_tmp(tmp);

	printf("\n");
	printf("%d\n", i + 1);
	printf("%s\n", program->map.map[i]);

	// ...

}
