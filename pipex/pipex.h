/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:15:33 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/03 06:50:31 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include"libft/libft.h"
# include"ft_printf/ft_printf.h"

//pipex.c
void	execute(char *argv_i, char **path, char **envp);
void	child_process(int *fd, char **argv, char **path, char **envp);
void	parent_process(int *fd, char **argv, char **path, char **envp);

//redirect.c
int		input_redirect(char *infile);
int		output_redirect(char *outfile);

//utils.c
char	**split_path(char **envp);
void	print_err(char *message, int err_code);
void	exit_program(int err_code);

#endif
