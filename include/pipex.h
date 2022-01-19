/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:22:56 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/19 19:38:43 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h> //delete

typedef struct s_pipex
{
	char	**envp;
}			t_pipex;

#endif
