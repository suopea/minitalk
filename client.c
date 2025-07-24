/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:23:47 by username          #+#    #+#             */
/*   Updated: 2025/07/23 15:27:40 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>

static int	server_says_hi(int server);
static void	send(int server, char *message);
static void	handler(int signal, siginfo_t *info, void *context);
static void	send_null(int server);

static volatile int	g_signal;

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	int					server;

	if (argc != 3)
	{
		ft_printf("Give me one pid and one message\n");
		return (1);
	}
	if (!all_digits(argv[1])
		|| ft_atoi_flew_over(argv[1], &server) || server < 0)
	{
		ft_printf("%s? I've seen better pid's\n", argv[1]);
		return (1);
	}
	sigact = install_handler(handler);
	if (server_says_hi(server))
	{
		send(server, ft_itoa(ft_strlen(argv[2])));
		send(server, argv[2]);
	}
	(void)sigact;
	return (0);
}

static int	server_says_hi(int server)
{
	int	time_waited;

	time_waited = 0;
	g_signal = 0;
	kill(server, SIGUSR1);
	while (time_waited <= PATIENCE && !g_signal)
	{
		usleep(NAPTIME);
		time_waited++;
	}
	if (time_waited > PATIENCE)
	{
		ft_printf("I think there's no one there\n");
		return (0);
	}
	g_signal = 0;
	return (1);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGINT)
		g_signal = SIGINT;
	else if (signal == SIGUSR1 || signal == SIGUSR2)
		g_signal = signal;
	(void)info;
	(void)context;
}

static void	send(int server, char *message)
{
	size_t	index;
	int		bit;

	index = 0;
	while (message[index])
	{
		g_signal = 0;
		bit = 0;
		while (bit < 8)
		{
			kill(server, get_next_bit_as_signal(message[index], &bit));
			while (!g_signal)
				usleep(NAPTIME);
			usleep(NAPTIME);
		}
		if (g_signal == SIGUSR2)
		{
			ft_printf("server says no :(\n");
			return ;
		}
		index++;
	}
	send_null(server);
}

static void	send_null(int server)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_signal = 0;
		kill(server, SIGUSR1);
		while (!g_signal)
			usleep(NAPTIME);
		usleep(NAPTIME);
		i++;
	}
}
