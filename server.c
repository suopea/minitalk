/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:44:26 by username          #+#    #+#             */
/*   Updated: 2025/07/23 15:25:50 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t *info, void *context);
static void	receive(int signal, siginfo_t *info);
static void	free_and_error(char *length, char *message);
static void	add_bit_to_string(int signal, char **str);

static t_signal_data g_data;

int	main(void)
{
	struct sigaction	sigact;

	sigact = install_handler(handler);
	g_data.phase = idle;
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
	static char	*length;
	static char *message;

	// ft_printf("phase %i, length '%s', message '%s'\n", g_data.phase, length, message);
	if (g_data.phase == idle)
	{
		length = ft_calloc(21, 1);
		if (!length)
		{
			free_and_error(length, NULL);
			return ;
		}
		g_data.sender = info->si_pid;
		g_data.phase = receiving_length;
	}
	if (g_data.phase == receiving_length)
		add_bit_to_string(signal, &length);
	if (g_data.phase == length_ready)
	{
		message = ft_calloc(ft_atoi(length) + 1, 1);
		if (!message)
		{
			free_and_error(length, message);
			return ;
		}
		free(length);
		length = NULL;
		g_data.phase += 1;
		return ;
	}
	if (g_data.phase == receiving_message)
		add_bit_to_string(signal, &message);
	if (g_data.phase == message_ready)
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
		g_data.sender = 0;
		g_data.phase = idle;
	}
}

static void	free_and_error(char *length, char *message)
{
	if (length)
		free(length);
	if (message)
		free(message);
	kill(g_data.sender, SIGUSR2);
}

static void	add_bit_to_string(int signal, char **str)
{
	int				bit_to_add;
	static int		bit_position;
	static size_t	index;

	bit_to_add = !!(signal == SIGUSR2);
	// ft_printf("%i", bit_to_add);
	(*str)[index] = bit_to_add << bit_position | (*str)[index];
	bit_position++;
	if (bit_position == 8)
	{
		// ft_printf("\nFULL BYTE %i (%c))\n", (int)(*str)[index], (*str)[index]);
		bit_position = 0;
		index++;
		if (!(*str)[index - 1])
		{
			// ft_printf("%s", (*str));
			g_data.phase += 1;
			index = 0;
		}
	}
	kill(g_data.sender, SIGUSR1);
}
