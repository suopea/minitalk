/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:49:11 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 10:59:14 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Applies the function f to each character of the
	string s, passing its index as the first argument
	and the character itself as the second. A new
	string is created (using malloc(3)) to store the
	results from the successive applications of f.
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (!s || !f)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
