/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:23:53 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/02 15:00:05 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	copies up to (size - 1) chars from the 0-terminated string src to dst,
	0-terminating the result

		Unlike strncpy, this takes the full size of the buffer (not just
	the length) and guarantees to NUL-terminate the result (as long as
	size is larger than 0)

		A byte for the NUL should be included in size. src must be 
	NUL-terminated.

		returns the total length of the string it tried to create, meaning
	the length of src. 
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (i + 1 < size && size > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (len);
}
