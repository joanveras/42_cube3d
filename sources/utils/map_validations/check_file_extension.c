/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:46:57 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:05:13 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

void	check_file_extension( t_program *program, char *line )
{
	char	*file_extension;

	if (!line)
		error_message(program, INVALID_PATH);

	file_extension = ft_strtrim(ft_strrchr(line, '.'), " \t");

	if (!ft_strncmp(file_extension, ".xpm", ft_strlen(file_extension)));
	{
		free(file_extension);
		return ;
	}

	free(file_extension);

	error_message(program, INVALID_PATH);
}
