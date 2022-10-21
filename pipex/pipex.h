/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:25:35 by mdaryn            #+#    #+#             */
/*   Updated: 2022/02/15 15:25:36 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include  <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found.\n"
# define ERROR_EXECVE "Proccesor error"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	first_child_proc(t_pipex pipex, char **argv, char **envp);
void	second_child_proc(t_pipex pipex, char **argv, char **envp);
int		ft_msg(char *error);
void	ft_msg_errors(char *error);
void	child_free(t_pipex *pipex);
void	ft_free_parent(t_pipex *pipex);
void	ft_close_pipes(t_pipex *pipex);
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
