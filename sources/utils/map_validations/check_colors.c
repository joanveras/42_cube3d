/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:32:08 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:09:27 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	set_rgb(int *r, int *g, int *b,
	const char *str, int index)
{
	if (index == 0)
		*r = ft_atoi(str);
	else if (index == 1)
		*g = ft_atoi(str);
	else if (index == 2)
		*b = ft_atoi(str);
}

static int	is_next_char_a_digit(t_program *program, const char *str)
{
	int	i;

	if (!str)
		return (0);

	i = 0;
	while (ft_isdigit(str[i]))
		i++;

	if (i == 0 || i > 3)
		error_message(program, INVALID_FORMAT);

	return (i);

}

static void	validate_rgb_format(t_program *program, char *line, int *ret)
{
	int	i, j, k;

	char	*str;

	i = 0;
	if (!line || line[i] == ',')
		error_message(program, INVALID_FORMAT);

	str = (char *)line;

	while (i < 3)
	{
		j = 0;
		if (str[j] == ',')
			j++;

		while (str[j] == ' ')
			j++;

		str = str + j;

		k = is_next_char_a_digit(program, str);

		set_rgb(&ret[0], &ret[1], &ret[2], str, i);

		str = str + k;

		j = 0;
		while (str[j] == ' ')
			j++;

		str = str + j;

		i++;
	}

	free(line);

}

int	*check_colors(t_program *program, char **map, int *i)
{

	int	j, k;
	int	*ret;

	ret = malloc(sizeof(int) * 3);

	j = *i;
	k = 0;
	while (map[j][k] == ' ')
		k++;

	if (map[j][k] != 'F' && map[j][k] != 'C')
		error_message(program, INVALID_FORMAT);
	else if (map[j][k + 1] != ' ')
		error_message(program, INVALID_FORMAT);

	validate_rgb_format(program, ft_strtrim(&map[j][k + 1], " \t\n"), ret);

	(*i)++;

	return (ret);

}
