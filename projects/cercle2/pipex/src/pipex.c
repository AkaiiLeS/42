/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:23:21 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/24 20:00:27 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_pipex p;

    if  (ac < 5)
    {
        if (!ft_strncmp("here_doc", av[1], 9))
            return (fail_msg("Try again: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
        return (fail_msg("Try again: ", "./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
    }
    else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
        return (fail_msg("Try again: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
    if (!envp || envp[0][0] == '\0')
        clean_exit(fail_msg("There's an issue with the environment, did you try to remove it you sneaky litlle rat ?!", "", "", 1), &p);
    p = pipex_i(ac, av, envp);
    return (0);
}

