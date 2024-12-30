/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:27:07 by jveras2           #+#    #+#             */
/*   Updated: 2024/12/27 16:25:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_digits(long nb)
{
	int	counter;

	if (nb == 0)
		return (1);
	counter = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

static void	handle_positives(char *dest, int signal, int index, long n)
{
	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		dest[(index--) + signal] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_negative;
	long	l;
	char	*string;

	l = n;
	is_negative = (l < 0);
	if (is_negative)
		l = -l;
	i = count_digits(l);
	string = malloc(i + is_negative + 1);
	if (!string)
		return (NULL);
	string[(i--) + is_negative] = '\0';
	handle_positives(string, is_negative, i, l);
	if (is_negative)
		string[0] = '-';
	return (string);
}
