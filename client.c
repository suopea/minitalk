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
#include <stdio.h>

static void send(int server, char *message);
static int get_next_bit_as_signal(char c, int *bit);
static void	handler(int signal, siginfo_t *info, void *context);
static void	send_null(int server);

static t_signal_data g_data;

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	int					server;
	
	if (argc != 3)
	{
		ft_printf("Provide one and only one argument\n");
		return (1);
	}
	if (ft_atoi_flew_over(argv[1], &server))
	{
		ft_printf("Server pid overflow\n");
		return (1);
	}
	sigact = install_handler(handler);
	send(server, ft_itoa(ft_strlen(argv[2])));
	send(server, argv[2]);
	return (0);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGINT)
		g_data.signal = SIGINT;
	else if (signal == SIGUSR1 || signal == SIGUSR2)
		g_data.signal = signal;
	(void)info;
	(void)context;
}

static void send(int server, char *message)
{
	size_t	index;
	int		bit;

	index = 0;
	while (message[index])
	{
		g_data.signal = 0;
		bit = 0;
		while (bit < 8)
		{
			kill(server, get_next_bit_as_signal(message[index], &bit));
			while (!g_data.signal)
				usleep(NAP_TIME);
			usleep(NAP_TIME);
		}
		printf("\n");
		if (g_data.signal == SIGUSR2)
		{
			ft_printf("server says no :(");
			return ;
		}
		index++;
	}
	send_null(server);
	ft_printf("message sent\n");
}

static void	send_null(int server)
{
	int	i;

	i = 0;
	ft_printf("sending null bit ");
	while (i < 8)
	{
		g_data.signal = 0;
		ft_printf("%i", i);
		kill(server, SIGUSR1);
		while (!g_data.signal)
			usleep(NAP_TIME);
		usleep(NAP_TIME);
		i++;
	}
	ft_printf("\n");
}

static int get_next_bit_as_signal(char c, int *bit)
{
	int next_bit;

	next_bit = !!(1 << *bit & c);
	printf("%i", next_bit);
	*bit = *bit + 1;
	if (next_bit)
		return (SIGUSR2);
	return (SIGUSR1);
}
