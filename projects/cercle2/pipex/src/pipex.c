/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:23:21 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/25 12:24:57 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/wait.h>
#include <unistd.h>

static void redirect_file(int in, int out, t_pipex *p)
{
    if (dup2(in, STDIN_FILENO) == -1)
        clean_exit(1, p);
    if (dup2(out, STDOUT_FILENO) == -1)
        clean_exit(1, p);
}

static void set_child(t_pipex *p)
{
    if (p->child == 0)
        redirect_file(p->fdi, p->pipe[1], p);
    else if (p->child == p->cmds_nu - 1)
        redirect_file(p->pipe[2 * p->child - 2], p->fdo, p);
    else
        redirect_file(p->pipe[2 * p->child - 2], p->pipe[2 * p->child + 1], p);
    clean_fds(p);
    if (p->cmd_param == NULL || p->path == NULL)
        clean_exit(fail_msg(p->cmd_param[0], ": ", strerror(errno), 1), p);
    if (execve(p->path, p->cmd_param, p->envp) == -1)
        clean_exit(fail_msg(p->cmd_param[0], ": ", strerror(errno), 1), p);
}

static int  set_parent(t_pipex *p)
{
    pid_t   waitp;
    int exiti;
    int child_info;

    clean_fds(p);
    p->child--;
    exiti = 1;
    while (p->child >= 0)
    {
        waitp = waitpid(p->pids[p->child], &child_info, 0);
        if (waitp == p->pids[p->cmds_nu - 1])
        {
            if ((p->child == (p->cmds_nu - 1)) && WIFEXITED(child_info))
                    exiti = WEXITSTATUS(child_info);
        }
        p->child--;
    }
    free(p->pipe);
    free(p->pids);
    return (exiti);
}

static int  pipex(t_pipex *p)
{
    int exiti;

    if (pipe(p->pipe) == -1)
        clean_exit(fail_msg("pipe error", ": ", strerror(errno), 1), p);
    p->child = 0;
    while (p->child < p->cmds_nu)
    {
        p->cmd_param = ft_split(p->av[p->child + 2 + p->heredoc], ' ');
        if (!p->cmd_param)
            clean_exit(fail_msg("split error", "", "", 1), p);
        p->path = get_cmd(p->cmd_param[0], p);
        p->pids[p->child] = fork();
        if (p->pids[p->child] == -1)
            clean_exit(fail_msg("fork error", ": ", strerror(errno), 1), p);
        else if(p->pids[p->child] == 0)
            set_child(p);
        free_m(p->path, p->cmd_param);
        p->child++;
    }
    exiti = set_parent(p);
    if (p->heredoc == 1)
        unlink(".hd.tmp");
    return (exiti);
}

int main(int ac, char **av, char **envp)
{
    t_pipex p;
    int exiti;

    if  (ac < 5)
    {
        if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
            return (fail_msg("Try again: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
        return (fail_msg("Try again: ", "./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
    }
    else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
        return (fail_msg("Try again: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
    if (!envp || envp[0][0] == '\0')
        clean_exit(fail_msg("There's an issue with the environment, did you try to remove it you sneaky litlle rat ?!", "", "", 1), &p);
    p = pipex_i(ac, av, envp);
    exiti = pipex(&p);
    return (exiti);
}

