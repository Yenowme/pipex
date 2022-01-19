/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:22:55 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/19 19:39:36 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	err_exit(char *str)
{
	ft_putstr_fd(str, 0);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		printf("hi %s", argv[1]);
		pipex.envp = env;
	}
	else
		return (err_exit("argument must be four."));
	return (0);
}
