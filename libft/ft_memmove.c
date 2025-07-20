/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:50:48 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/05 10:11:47 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*forward_copy(char *dest, const char *src, size_t n);
static void	*rev_copy(char *dest, const char *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_c;
	char		*dest_c;

	if ((!src || !dest) && n != 0)
		return (NULL);
	src_c = src;
	dest_c = dest;
	if (src == dest)
		return (dest);
	if (src > dest)
		return (forward_copy(dest_c, src_c, n));
	return (rev_copy(dest_c, src_c, n));
}

static void	*forward_copy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}

static void	*rev_copy(char *dest, const char *src, size_t n)
{
	int			i;

	i = n - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return ((void *)dest);
}
