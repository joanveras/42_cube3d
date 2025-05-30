/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:41 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"
#include "../../../includes/get_next_line.h"

static int	count_lines(char *path)
{
	int		fd;
	int		counter;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "error: COULD NOT OPEN FILE\n", 27);
		exit(EXIT_FAILURE);
	}
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

static void	fill_file(char *path, char **file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		file[i] = ft_strdup(line);
		if (ft_strchr(file[i], '\n'))
			file[i][ft_strlen(file[i]) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	close(fd);
}

char	**open_file(char *path)
{
	char	**file;

	file = malloc((count_lines(path) + 1) * sizeof(char *));
	if (!file)
	{
		ft_putstr_fd("Memory allocation failure:: allocating (char **file)", 2);
		exit(EXIT_FAILURE);
	}
	fill_file(path, file);
	return (file);
}
