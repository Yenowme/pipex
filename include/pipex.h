/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:22:56 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/25 18:18:12 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

# define EXIT_ERR 1

void	exit_error(void);
char	*check_access(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
int		arg_err(void);

#endif
