/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_flew_over.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:51:28 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/05 12:45:24 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_flew_over(const char *in, int *out)
{
	int		sign;
	long	temp;
	int		i;

	i = 0;
	temp = 0;
	sign = 1;
	while (in[i] == ' ' || (in[i] >= 9 && in[i] <= 13))
		i++;
	if (in[i] == '-')
		sign *= -1;
	if (in[i] == '+' || in[i] == '-')
		i++;
	while (ft_isdigit(in[i]))
	{
		if ((0 < sign && (int)(temp * 10 + in[i] - '0') < temp)
			|| (0 > sign && (int)(temp * 10 + in[i] - '0' - 1) < temp))
			return (1);
		temp = temp * 10 + in[i] - '0';
		i++;
	}
	temp *= sign;
	*out = temp;
	return (0);
}
