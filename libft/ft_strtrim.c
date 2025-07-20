/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:30:51 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/01 12:45:43 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assign_range(char *s1, char *set, size_t *start, size_t *out_len);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	out_len;

	if (!s1 || !set)
		return (NULL);
	assign_range((char *)s1, (char *)set, &start, &out_len);
	return (ft_substr(s1, start, out_len));
}

static void	assign_range(char *s1, char *set, size_t *start, size_t *out_len)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	*start = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && *start < i)
		i--;
	*out_len = i + 1 - *start;
}
