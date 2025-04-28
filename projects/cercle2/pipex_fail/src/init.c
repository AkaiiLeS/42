/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:00:50 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/28 11:52:23 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipe_pop(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->cmds_nu - 1)
	{
		if (pipe(p->pipe + 2 * i) == -1)
			clean_exit(fail_msg("Failed to pop the pipe", "", "", 1), p);
		i++;
	}
}

static t_pipex	clean_sheet(void)
{
	t_pipex	p;

	p.ac = -1;
	p.av = NULL;
	p.envp = NULL;
	p.heredoc = 0;
	p.fdi = -1;
	p.fdo = -1;
	p.pipe = NULL;
	p.cmds_nu = -1;
	p.child = -1;
	p.path = NULL;
	p.cmd_param = NULL;
	p.pids = NULL;
	return (p);
}

t_pipex	pipex_i(int ac, char **av, char **envp)
{
	t_pipex	pi;

	pi = clean_sheet();
	pi.ac = ac;
	pi.av = av;
	pi.envp = envp;
	if (!ft_strncmp("here_doc", av[1], 9))
		pi.heredoc = 1;
	file1(&pi);
	file2(&pi);
	pi.cmds_nu = ac - 3 - pi.heredoc;
	pi.pids = malloc(sizeof * pi.pids * pi.cmds_nu);
	if (!pi.pids)
		clean_exit(fail_msg("No more space in your memory, can't stock PIDs.",
				strerror(errno), "", 1), &pi);
	pi.pipe = malloc(sizeof * pi.pipe * 2 * (pi.cmds_nu - 1));
	if (!pi.pipe)
		clean_exit(fail_msg("No more space in your memory, can't stock pipes.",
				"", "", 1), &pi);
	pipe_pop(&pi);
	return (pi);
}
