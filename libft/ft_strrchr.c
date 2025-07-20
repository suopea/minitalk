/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:05:53 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 13:25:50 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	if (!s || !ft_strchr(s, c))
		return (NULL);
	out = (char *) s;
	if (!c)
		return (out + ft_strlen(s));
	while (ft_strchr(out + 1, c))
		out = ft_strchr(out + 1, c);
	return (out);
}
