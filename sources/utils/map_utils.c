/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:41 by jveras            #+#    #+#             */
/*   Updated: 2024/12/28 02:16:05 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/cube3d.h"
#include "../../includes/get_next_line.h"

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

static void	fill_map(char *path, char **map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = ft_strdup(line);
		if (ft_strchr(map[i], '\n'))
			map[i][ft_strlen(map[i]) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
}

char	**open_map(char *path)
{
	char	**map;

	map = malloc((count_lines(path) + 1) * sizeof(char *));
	if (!map)
	{
		write(STDERR_FILENO, "Memory allocation failure:: allocating (char **map)", 52);
		exit(EXIT_FAILURE);
	}
	fill_map(path, map);
	return (map);
}
