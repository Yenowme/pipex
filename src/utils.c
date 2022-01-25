/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:19:13 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/25 18:17:47 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_error(void)
{
	perror("\033[31mError");
	exit(EXIT_ERR);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*check_access(char *cmd, char **envp)
{	
	int		i;
	char	*real_cmd;
	char	*slash_path;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		slash_path = ft_strjoin(paths[i], "/");
		real_cmd = ft_strjoin(slash_path, cmd);
		if (access(real_cmd, X_OK) == 0)
		{
			free_paths(paths);
			return (real_cmd);
		}
		free(slash_path);
		free(real_cmd);
		i++;
	}
	free_paths(paths);
	return (0);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	*real_cmd;

	argv = ft_split(cmd, ' ');
	real_cmd = check_access(argv[0], envp);
	if (!real_cmd)
		exit_error();
	execve(real_cmd, argv, envp);
}

int	arg_err(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
	return (1);
}
