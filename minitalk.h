/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:24:27 by username          #+#    #+#             */
/*   Updated: 2025/07/23 15:16:59 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

enum e_phase
{
	idle,
	receiving_length,
	length_ready,
	receiving_message,
	message_ready,
};

typedef struct s_signal_data
{
	pid_t					sender;
	volatile sig_atomic_t	signal;
	volatile sig_atomic_t	length;
	enum e_phase			phase;
}	t_signal_data;

struct sigaction	install_handler(void (*handler)(int, siginfo_t *, void *));

#endif
