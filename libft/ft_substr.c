/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:44:57 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/06 12:31:53 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	s: substring source

	start: substring position in source
	len: max length of substring

	return the substring or NULL if alloc fails

	Allocates memory using malloc and returns a substring
	from the string s. Substring starts at start and has 
	a maximum length of len
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*out;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
