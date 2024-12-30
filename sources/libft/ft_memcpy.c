/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:49:12 by jveras2           #+#    #+#             */
/*   Updated: 2024/12/27 16:25:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*new_dest;
	const char	*new_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	new_dest = dest;
	new_src = (const char *) src;
	while (n--)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (new_dest);
}
