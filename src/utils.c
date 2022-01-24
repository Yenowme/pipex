/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:19:13 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/24 17:19:56 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_error(void)
{
	perror("\033[31mError");
	exit(EXIT_ERR);
}

char	*check_access(char *cmd, char **envp)
{	
	int		i;
	char	*real_cmd;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	while (*paths)
	{
		real_cmd = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(real_cmd, X_OK) == 0)
			return (real_cmd);
		free(real_cmd);
		paths++;
	}
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

int	arg_err(char *str)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
