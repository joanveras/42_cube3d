/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_abbrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:06:07 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:03:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

// If the characthers match the directions (SO, NO, ...), calls check_path function
static int	check_characthers(t_program *program, char *line, int i, char c1, char c2)
{
	if (line[i] == c1)
	{
		if (line[i + 1] && (line[i + 1] == c2 || line[i + 1] == ' '))
		{
			check_path(program, c1, c2, &line[i + 2]);
			return (1);
		}
		error_message(program, "Invalid direction abbreviation\n");
	}
	return (0);
}

void	check_abbrev( t_program *program, char *line, int *dir_counter )
{
	int	i;

	if (!line)
		return ;

	i = 0;
	while ( line[i] == '\n' )
		i++;
	while ( line[i] == ' ' )
		i++;

	while (line[i])
	{

		if (check_characthers(program, line, i, 'N', 'O'))
		{
			(*dir_counter)++;
			break;
		}
		else if (check_characthers(program, line, i, 'S', 'O'))
		{
			(*dir_counter)++;
			break;
		}
		else if (check_characthers(program, line, i, 'W', 'E'))
		{
			(*dir_counter)++;
			break;
		}
		else if (check_characthers(program, line, i, 'E', 'A'))
		{
			(*dir_counter)++;
			break;
		}

		i++;

	}

}
