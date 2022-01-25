/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:22:55 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/25 18:18:01 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child(int *fd, char **argv, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		exit_error();
	if (dup2(filein, STDIN_FILENO) == -1)
		exit_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_error();
	close(fd[0]);
	exec_cmd(argv[2], envp);
}

void	parent(int *fd, char **argv, char **envp)
{
	int	fileout;
	int	state;

	waitpid(-1, &state, WNOHANG);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		exit_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_error();
	if (dup2(fileout, STDOUT_FILENO) == -1)
		exit_error();
	close(fd[1]);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid_rt;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit_error();
		pid_rt = fork();
		if (pid_rt == -1)
			return (1);
		if (pid_rt == 0)
			child(fd, argv, envp);
		else if (pid_rt > 0)
			parent(fd, argv, envp);
	}
	else
		arg_err();
	return (0);
}
