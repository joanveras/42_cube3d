/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:23 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:03:22 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

// Saves the line index for next validation functions
void	check_directions( t_program *program, int *i )
{

	int	dir_counter;
	int	j;

	dir_counter = 0;
	
	j = 0;
	while (program->map.map[j])
	{
		if (ft_strchr(program->map.map[j], 'F') && ft_strchr(program->map.map[j], ','))
		{
			j = 0;
			while (!ft_strchr(program->map.map[j], ','))
			{
				check_abbrev(program, program->map.map[j], &dir_counter);

				j++;
			}

			if (dir_counter < 4)
				error_message(program, "Missing Direction\nWrong order of information in the file\n");

			break ;
		}
		j++;
	}

	if (!program->map.map[j])
		error_message(program, "Missing information in the file");

	*i = j;

}
