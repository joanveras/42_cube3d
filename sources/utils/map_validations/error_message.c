/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:58 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:20:41 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

static void	error_safe_exit(t_program *program)
{
	free_map(&program->map);
	mlx_destroy_window(program->mlx, program->mlx_win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(EXIT_SUCCESS);
}

void	error_message( t_program *program, const char *message )
{
	ft_putstr_fd((char *)message, STDERR_FILENO);
	error_safe_exit(program);
}
