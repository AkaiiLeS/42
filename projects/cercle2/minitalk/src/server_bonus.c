/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:29:18 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 20:29:35 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_str(unsigned char c, int pid)
{
	static char		buffer[1000000000];
	static size_t	i = 0;

	if (c == '\0')
	{
		buffer[i] = '\0';
		ft_printf("%s\n", buffer);
		kill(pid, SIGUSR2);
		i = 0;
	}
	else
		buffer[i++] = c;
}

void	handler(int s, siginfo_t *info, void *content)
{
	static int				bits = 0;
	static unsigned char	c = 0;

	(void)content;
	c = (c << 1) | (s == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		handle_str(c, info->si_pid);
		bits = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
