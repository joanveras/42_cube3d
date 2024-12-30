/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:29:47 by jveras2           #+#    #+#             */
/*   Updated: 2024/12/27 16:25:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j])
				&& big[i + j] && ((i + j) < len))
				j++;
			if (!little[j])
				return (((char *) big) + i);
		}
		i++;
	}
	return (NULL);
}
