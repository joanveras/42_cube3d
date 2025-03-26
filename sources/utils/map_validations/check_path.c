/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:20 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:06:32 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static void	get_path(t_program *program, char c1, char c2, char *line)
{
	if (c1 == 'N' && c2 == 'O')
		program->textures.north = line;
	else if (c1 == 'S' && c2 == 'O')
		program->textures.south = line;
	else if (c1 == 'W' && c2 == 'E')
		program->textures.west = line;
	else if (c1 == 'E' && c2 == 'A')
		program->textures.east = line;
}

// First test for the initial './' characthers.
// If passes, then check if it has the extension '.xpm'
// And after, if it's a real file
void	check_path( t_program *program, char c1, char c2, char *line )
{
	int	i;

	i = 0;
	if (!line || line[i] == '\n')
		error_message(program, INVALID_PATH);

	while (line[i] == ' ')
		i++;

	if (!line || line[i] == '\n')
		error_message(program, INVALID_PATH);

	if (line[i] && line[i] != '\n')
	{
		check_file_extension(program, &line[i]);
		is_a_file(program, &line[i]);
		get_path(program, c1, c2, &line[i]);
		return ;
	}
	error_message(program, INVALID_PATH);
}
