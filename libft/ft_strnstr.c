/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:30:19 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 11:18:44 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_lil;

	if (!little || !big)
		return (NULL);
	if (!little[0])
		return ((char *) big);
	i_big = 0;
	while (big[i_big] && i_big <= len)
	{
		i_lil = 0;
		while (little[i_lil] == big[i_big + i_lil]
			&& little[i_lil] && i_big + i_lil < len)
			i_lil++;
		if (!little[i_lil])
			return ((char *)big + i_big);
		i_big++;
	}
	return (NULL);
}
