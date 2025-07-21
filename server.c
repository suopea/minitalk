/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:44:26 by username          #+#    #+#             */
/*   Updated: 2025/07/21 15:39:50 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t *info, void *context);
static void	receive(int signal, siginfo_t *info);

t_signal_data g_data;

int	main(void)
{
	struct sigaction	sigact;

	sigact = install_handler(handler);
	ft_printf("server pid:%d\n", getpid());
	while (g_data.signal != SIGINT)
		pause();
	return (0);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGINT)
		g_data.signal = SIGINT;
	else if (signal == SIGUSR1 || signal == SIGUSR2)
		receive(signal, info);
	(void)info;
	(void)context;
}

static void	receive(int signal, siginfo_t *info)
{
	g_data.sender = info->si_pid;
	ft_printf("server received %d from %d\n", signal, g_data.sender);
	kill(g_data.sender, SIGUSR1);
}
