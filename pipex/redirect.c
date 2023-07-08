/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:52:11 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/03 11:14:16 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	input_redirect(char *infile)
{
	int	input_fd;

	input_fd = open(infile, O_RDONLY);
	if (input_fd < 0)
	{
		print_err("file does not open\n", 0);
		return (0);
	}
	if (dup2(input_fd, STDIN_FILENO) < 0)
		print_err("dup error\n", 1);
	close(input_fd);
	return (1);
}

int	output_redirect(char *outfile)
{
	int	output_fd;

	output_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd < 0)
		print_err("file does not open\n", 1);
	if (dup2(output_fd, STDOUT_FILENO) < 0)
		print_err("dup error\n", 1);
	close(output_fd);
	return (1);
}
