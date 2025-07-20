/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:10:13 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 10:45:14 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_len_and_alloc(long int n, int *place);
static long	deal_with_sign(long temp, char *out);

char	*ft_itoa(int n)
{
	char	*out;
	int		place;
	int		i;
	long	temp;

	temp = n;
	i = 0;
	place = 1;
	out = find_len_and_alloc(n, &place);
	if (!out)
		return (NULL);
	temp = deal_with_sign(temp, out);
	if (out[0] == '-')
		i++;
	while (place > 1)
	{
		out[i] = (temp / place) + '0';
		temp = temp % place;
		place /= 10;
		i++;
	}
	out[i] = temp + '0';
	out[++i] = 0;
	return (out);
}

static long	deal_with_sign(long temp, char *out)
{
	out[0] = 0;
	if (temp < 0)
	{
		out[0] = '-';
		temp = -temp;
	}
	return (temp);
}

static char	*find_len_and_alloc(long int n, int *place)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (*place <= n / 10)
	{
		*place *= 10;
		len++;
	}
	return ((char *)malloc(len + 1));
}
