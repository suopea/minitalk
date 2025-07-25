/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:46:11 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/25 15:20:33 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define NAPTIME 100
# define PATIENCE 5000

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
	volatile pid_t			sender;
	volatile sig_atomic_t	signal;
	volatile sig_atomic_t	length;
	volatile enum e_phase	phase;
}	t_signal_data;

struct sigaction	install_handler(
						void (*handler)(int, siginfo_t *, void *));
int					all_digits(char *string);
int					get_next_bit_as_signal(char c, int *bit);
void				calloc_or_die(char **to_alloc, int size,
						char **the_other_string, t_signal_data *g_data);
void				initialize(char **length, char **message,
						t_signal_data *g_data, siginfo_t *info);

#endif
