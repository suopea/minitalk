/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:08:50 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 10:58:10 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1: prefix
s2: suffix

Allocates memory and returns a new string,
which is the result of concatenating s1 and s2
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*out;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	out = malloc(s1_len + s2_len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, s1_len + 1);
	ft_strlcat(out, s2, s1_len + s2_len + 1);
	return (out);
}
