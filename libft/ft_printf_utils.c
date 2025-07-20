/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:54:46 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/29 17:11:46 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_reverse(char *buffer, int len)
{
	char	out[24];
	int		index_out;

	index_out = 0;
	while (index_out <= len)
	{
		out[index_out] = buffer[len - index_out - 1];
		index_out++;
	}
	return (write(1, out, len));
}

int	print_pointer(unsigned long long pointer)
{
	char				buffer[32];
	int					i;

	if (!pointer)
		return (write(1, "(nil)", 5));
	i = 0;
	while (pointer > 0)
	{
		buffer[i++] = "0123456789abcdef"[pointer % 16];
		pointer /= 16;
	}
	buffer[i++] = 'x';
	buffer[i++] = '0';
	return (write_reverse(buffer, i--));
}

int	print_base(long long nbr, char *base)
{
	char		buffer[32];
	int			i;
	int			positive;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	positive = 1;
	if (nbr < 0)
	{
		positive = 0;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	if (!positive)
		buffer[i++] = '-';
	return (write_reverse(buffer, i--));
}
