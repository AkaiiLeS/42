/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:49:58 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/25 13:46:17 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    file1(t_pipex *p)
{
    if (p->heredoc == 1)
    {
        hdparse(p);
        p->fdi = open(".hd.tmp", O_RDONLY);
        if (p->fdi == -1)
            clean_exit(fail_msg("here_doc", ": ", strerror(errno), 1), p);
    }
    else
    {
        p->fdi = open(p->av[1], O_RDONLY, 644);
        if (p->fdi == -1)
            clean_exit(fail_msg(strerror(errno), ": ", p->av[1], 1), p);
    }
}

void file2(t_pipex *p)
{
    if (p->heredoc == 1)
        p->fdo = open(p->av[p->ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        p->fdo = open(p->av[p->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(p->fdo == -1)
        fail_msg(strerror(errno), ": ", p->av[p->ac - 1], 1);
}

void hdparse(t_pipex *p)
{
    int tmp;
    int fd_std;
    char    *buff;

    tmp = open(".hd.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_std = dup(STDIN_FILENO);
    if (tmp == -1)
        clean_exit(fail_msg("here_doc", ": ", strerror(errno), 1), p);
    buff = "";
    while (1)
    {
        ft_putstr_fd("here_doc > ", 1);
        buff = get_next_line(fd_std);
        if (buff == NULL)
            break ;
        if (ft_strlen(p->av[2]) + 1 == ft_strlen(buff)
                && !ft_strncmp(buff, p->av[2], ft_strlen(p->av[2] + 1)))
            close(fd_std);
        else
            ft_putstr_fd(buff, tmp);
        free(buff);
    }
    close(tmp);
}
