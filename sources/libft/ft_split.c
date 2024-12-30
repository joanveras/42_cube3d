/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:57:53 by jveras2           #+#    #+#             */
/*   Updated: 2024/12/27 16:25:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_words(const char *str, const char sep)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			counter++;
			while (str[i] && str[i] != sep)
				i++;
		}
		i++;
	}
	return (counter);
}

static	char	*copy_word(const char *s, int pos, const char sep)
{
	int		i;
	int		len;
	int		foo;
	char	*word;

	while (s[pos] == sep)
		pos++;
	len = 0;
	foo = pos;
	while (s[foo] && s[foo] != sep)
	{
		len++;
		foo++;
	}
	word = malloc(len + 1);
	i = 0;
	while (s[pos] && s[pos] != sep)
	{
		word[i] = s[pos];
		i++;
		pos++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	size_t	i;
	size_t	j;
	char	**strs;

	strs = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!s || !strs)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			strs[j++] = copy_word(s, index, c);
			index = -1;
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}
