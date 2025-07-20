/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:22:24 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 16:42:10 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	allocates memory for an array of nmemb elements of size bytes each and
	returns a pointer to the allocated memory. The memory is set to zero

	if nmemb or size is 0, then calloc returns NULL or a unique pointer
	value that can be freed 

	if nmemb * size results in overflow, calloc returns an error 
		malloc wouldn't detect this - malloc(nmemb * size)

	on error, returns NULL
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	total;

	if (!nmemb || !size)
		return (malloc(1));
	total = nmemb * size;
	if (total / nmemb != size)
		return (NULL);
	out = malloc(total);
	if (!out)
		return (NULL);
	ft_bzero(out, size * nmemb);
	return (out);
}
