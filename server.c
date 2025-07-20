/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:24:12 by username          #+#    #+#             */
/*   Updated: 2025/07/20 19:42:26 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static struct sigaction install_handler(void);
static void				handler(int signal, siginfo_t *info, void *context);
void					receive(int signal);

t_signal_data g_signal;

int	main(void)
{
	struct sigaction	sigact;

	ft_printf("server pid:%d\n", getpid());
	sigact = install_handler();
	while (g_signal.signal != SIGINT)
		pause();
	return (0);
}

static struct sigaction install_handler(void)
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	sigaction(SIGINT, &sigact, NULL);
	return (sigact);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGINT)
		g_signal.signal = SIGINT;
	else if (signal == SIGUSR1 || signal == SIGUSR2)
		receive(signal);
	(void)info;
	(void)context;
}

void	receive(int signal)
{
	ft_printf("%d\n", signal);
}
