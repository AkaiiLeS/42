/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:10:32 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/25 15:28:05 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char *pars_env(char **envp)
{
    char *path;
    int i;

    i = 0;
    path = NULL;
    while (envp[i] != NULL && envp[i][0] != '\0')
    {
        path = ft_strnstr(envp[i], "PATH=", 5);
        if (path)
        {
            path = ft_substr(path, 5, ft_strlen(path));
            break ;
        }
        i++;
    }
    return (path);
}


static char **give_paths(char **paths)
{
    int i;
    char *tmp;

    i = 0;
    tmp = NULL;
    while (paths[i])
    {
        tmp = paths[i];
        paths[i] = ft_strjoin(paths[i], "/");
        free_m(tmp, NULL);
        i++;
    }
    return (paths);
}
static  char **env_paths(char **envp)
{
    char *env_s;
    char **paths;

    env_s = pars_env(envp);
    if (!env_s)
        return (NULL);
    paths = ft_split(env_s, ':');
    free_m(env_s, NULL);
    if (!paths)
        return (NULL);
    paths = give_paths(paths);
    if (!paths)
        return (NULL);
    return (paths);
}

static char *pars_cmd(char *cmd, char **paths)
{
    int i;
    char *cmd_p;

    cmd_p = NULL;
    i = 0;
    if (!cmd || !*cmd)
        return NULL;
    while (paths[i])
    {
        cmd_p = ft_strjoin(paths[i], cmd);
        if (!cmd_p)
        {
            free_m(NULL, paths);
            clean_exit(fail_msg("couldn't get path", "", "", 1), NULL);
        }
        if (access(cmd_p, F_OK | X_OK) == 0)
            return(cmd_p);
        free_m(cmd_p, NULL);
        i++;
    }
    return (NULL);
}
char *get_cmd(char *cmd, t_pipex *pipex)
{
    char **env_p;
    char *cmd_p;

    if (access(cmd, F_OK | X_OK) == 0)
        return (ft_strdup(cmd));
    env_p = env_paths(pipex->envp);
    if (!env_p)
        return (NULL);
    cmd_p = pars_cmd(cmd, env_p);
    if (!cmd_p)
        clean_exit(fail_msg("command not found", ": ", pipex->av[pipex->child + 2], 1), NULL);
    free_m(NULL, env_p);
    return (cmd_p);
}
