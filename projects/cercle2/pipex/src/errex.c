/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:54:21 by akaiissa          #+#    #+#             */
/*   Updated: 2025/03/10 16:29:53 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int fail_msg(char *s1, char *s2, char *s3, int error)
{
    ft_putstr_fd("Wrong ! ", 2);
    ft_putstr_fd(s1, 2);
    ft_putstr_fd(s2, 2);
    ft_putendl_fd(s3, 2);
    return (error);
}

void    clean_exit(int error, t_pipex *p)
{
    if (p)
    {
        clean_fds(p);
        if (p->pipe != NULL)
            free(p->pipe);
        if (p->pids != NULL)
            free(p->pids);
        if (p->cmd_param != NULL || p->path != NULL)
            free_m(p->path, p->cmd_param);
    }
    if (p->heredoc == 1)
        unlink(".h.tmp");
    exit(error);
}

void    free_m(char *malloc1, char **malloc2)
{
    int i;

    if (malloc2 != NULL)
    {
        i = 0;
        while (malloc2[i])
        {
            free (malloc2[i]);
            i++;
        }
        free(malloc2);
        malloc2 = NULL;
    }
    if (malloc1 != NULL)
    {
        free(malloc1);
        malloc1 = NULL;
    }
}

void clean_fds(t_pipex *p)
{
    if (p->fdi != -1)
        close(p->fdi);
    if (p->fdo != -1)
        close(p->fdo);
    close_pipes(p);
}

void    close_pipes(t_pipex *p)
{
    int i;

    i = 0;
    while (i < (p->cmds_nu - 1) * 2)
    {
        close(p->pipe[i]);
        i++;
    }
}

