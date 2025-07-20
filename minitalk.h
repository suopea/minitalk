/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:24:27 by username          #+#    #+#             */
/*   Updated: 2025/07/20 19:10:44 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_signal_data
{
	pid_t					client;
	volatile sig_atomic_t	signal;
	volatile sig_atomic_t	length;
}	t_signal_data;

#endif
