/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:17:42 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/28 12:06:14 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

// -- Struct -- //
typedef struct s_pipex
{
	char	**av;
	char	**envp;
	int		ac;
	int		heredoc;
	int		fdi;
	int		fdo;
	int		*pipe;
	int		cmds_nu;
	int		child;
	int		*pids;
	char	**cmd_param;
	char	*path;
}			t_pipex;

// -- Error and Exit foos -- //
void		free_m(char *malloc1, char **malloc2);
void		clean_exit(int error, t_pipex *p);
void		close_pipes(t_pipex *p);
void		clean_fds(t_pipex *p);
int			fail_msg(char *s1, char *s2, char *s3, int error);

// -- Files -- //
void		hdparse(t_pipex *p);
void		file2(t_pipex *p);
void		file1(t_pipex *p);

// -- Parsing --//
char		*get_cmd(char *cmd, t_pipex *pipex);

// -- Init -- //
t_pipex		pipex_i(int ac, char **av, char **envp);

#endif
