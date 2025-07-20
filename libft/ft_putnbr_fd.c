/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:27:59 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/05 10:20:11 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_digit(int i, int fd)
{
	write(fd, &i, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	put_digit(i % 10 + '0', fd);
}
