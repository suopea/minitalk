/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:46:03 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/25 15:20:21 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	server_says_hi(pid_t server);
static int	send(pid_t server, char *message);
static void	handler(int signal, siginfo_t *info, void *context);
static void	send_null(pid_t server);

static volatile sig_atomic_t	g_signal;

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	pid_t				server;
	char				*length;

	if (argc != 3)
		return (1);
	if (!all_digits(argv[1])
		|| ft_atoi_flew_over(argv[1], &server) || server < 0)
	{
		ft_printf("%s? I've seen better pid's\n", argv[1]);
		return (1);
	}
	sigact = install_handler(handler);
	if (server_says_hi(server))
	{
		length = ft_itoa(ft_strlen(argv[2]));
		if (!length)
			return (1);
		if (send(server, length))
			send(server, argv[2]);
		free(length);
	}
	return (0);
}

static int	server_says_hi(pid_t server)
{
	kill(server, SIGUSR1);
	usleep(PATIENCE);
	if (!g_signal)
	{
		ft_printf("I think there's no one there\n");
		return (0);
	}
	if (g_signal == SIGUSR2)
	{
		ft_printf("Length malloc fail\n");
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

static int	send(pid_t server, char *message)
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
			return (0);
		}
		index++;
	}
	send_null(server);
	return (1);
}

static void	send_null(pid_t server)
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
