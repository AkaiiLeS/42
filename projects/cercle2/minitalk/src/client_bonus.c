/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:34 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 20:28:05 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile sig_atomic_t	g_msg = 0;

void	send_signal(int pid, char *str)
{
	int				i;
	int				len;
	unsigned char	tmp;

	len = ft_strlen(str) + 1;
	while (len)
	{
		i = 8;
		tmp = *(str);
		while (i > 0)
		{
			i--;
			if (tmp >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_msg)
				usleep(100);
			g_msg = 0;
		}
		str++;
		len--;
	}
}

void	handler(int s, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (s == SIGUSR1)
		g_msg = 1;
	else if (s == SIGUSR2)
	{
		ft_printf("\e[1;32mMessage received by server.\e[0m\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Usage: [./client <SERVER PID> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_signal(pid, av[2]);
	return (EXIT_SUCCESS);
}
