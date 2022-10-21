/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:16:44 by mdaryn            #+#    #+#             */
/*   Updated: 2022/02/15 15:16:49 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		paths++;
	}
	return (NULL);
}

void	first_child_proc(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_msg(ERROR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		ft_msg(ERROR_EXECVE);
	else
		execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child_proc(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_msg(ERROR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		ft_msg(ERROR_EXECVE);
	else
		execve(pipex.cmd, pipex.cmd_args, envp);
}
