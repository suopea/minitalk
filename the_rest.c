/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:38:27 by username          #+#    #+#             */
/*   Updated: 2025/07/21 15:34:53 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct sigaction	install_handler(void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = handler;
	sigemptyset(&sigact.sa_mask);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	sigaction(SIGINT, &sigact, NULL);
	return (sigact);
}

void	calloc_or_die(char **to_alloc, int size, char **the_other_string,
			t_signal_data *g_data)
{
	(*to_alloc) = ft_calloc(size, 1);
	if (!(to_alloc))
	{
		if (*the_other_string)
		{
			free(*the_other_string);
			*the_other_string = NULL;
		}
		g_data->phase = idle;
		kill(g_data->sender, SIGUSR2);
	}
}

void	initialize(char **length, char **message, t_signal_data *g_data,
					siginfo_t *info)
{
	calloc_or_die(length, 21, message, g_data);
	g_data->sender = info->si_pid;
	g_data->phase = receiving_length;
	kill(g_data->sender, SIGUSR1);
}

int	get_next_bit_as_signal(char c, int *bit)
{
	int	next_bit;

	next_bit = !!(1 << *bit & c);
	*bit = *bit + 1;
	if (next_bit)
		return (SIGUSR2);
	return (SIGUSR1);
}

int	all_digits(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}
