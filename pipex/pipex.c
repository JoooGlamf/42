/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:25:54 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/03 11:59:59 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	execute(char *argv_i, char **path, char **envp)
{
	char	**args;
	char	*file;
	int		i;

	args = ft_split(argv_i, ' ');
	if (args == 0)
		print_err("split error\n", 1);
	if (args[0][0] == '/')
	{
		file = args[0];
		execve(file, args, 0);
	}
	i = -1;
	while (path[++i])
	{
		file = ft_strjoin(path[i], "/");
		file = ft_strjoin(file, args[0]);
		if (access(file, X_OK) == 0)
		{
			execve(file, args, envp);
		}
	}
	print_err("command not found\n", 127);
}

void	child_process(int *fd, char **argv, char **path, char **envp)
{
	close(fd[0]);
	input_redirect(argv[1]);
	if (dup2(fd[1], 1) < 0)
		print_err("dup error\n", 1);
	execute(argv[2], path, envp);
}

void	parent_process(int *fd, char **argv, char **path, char **envp)
{
	close(fd[1]);
	output_redirect(argv[4]);
	if (dup2(fd[0], 0))
		print_err("dup error\n", 1);
	execute(argv[3], path, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	char	**path;

	if (argc != 5)
		print_err("Bad Arguments\n", 1);
	path = split_path(envp);
	if (pipe(fd) < 0)
		print_err("pipe error\n", 1);
	pid = fork();
	if (pid < 0)
		print_err("fork error\n", 1);
	else if (pid == 0)
	{
		child_process(fd, argv, path, envp);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		parent_process(fd, argv, path, envp);
	}
}
