/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:31:11 by soojoo            #+#    #+#             */
/*   Updated: 2023/02/20 21:13:28 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

t_buffer	*find_right_storage(int fd, t_buffer *storage)
{
	t_buffer	*tmp;

	if (!storage->fd)
	{
		storage->fd = fd;
		return (storage);
	}
	tmp = storage;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd != fd)
	{
		tmp->next = (t_buffer *)malloc(sizeof(t_buffer));
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
		tmp->fd = fd;
		ft_bzero(tmp->string, BUFFER_SIZE + 1);
		tmp->next = 0;
	}
	return (tmp);
}

t_buffer	*check_fd_storage(int fd, t_buffer *storage)
{
	t_buffer	*tmp;

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	tmp = find_right_storage(fd, storage);
	if (!tmp)
		return (0);
	if (tmp->string[0] == 0)
	{
		tmp->len = read(fd, tmp->string, BUFFER_SIZE);
		if (tmp->len == 0 || tmp->len == -1)
		{
			ft_bzero(tmp->string, BUFFER_SIZE + 1);
			tmp->len = 0;
			tmp->nl = -1;
			if (tmp != storage)
				free_storage(fd, tmp, storage);
			return (0);
		}
		tmp->string[tmp->len] = 0;
		tmp->nl = find_nl(tmp->string);
	}
	return (tmp);
}

char	*make_line_until_nl(int fd, t_buffer *storage, char *output)
{
	while (storage->nl == -1)
	{
		output = ft_strjoin_free(output, storage->string, storage->len);
		if (!output)
			return (0);
		storage->len = read(fd, storage->string, BUFFER_SIZE);
		if (storage->len == -1)
		{
			free(output);
			ft_bzero(storage->string, BUFFER_SIZE + 1);
			storage->len = 0;
			storage->nl = -1;
			return (0);
		}
		storage->string[storage->len] = 0;
		if (storage->len == 0)
			return (output);
		storage->nl = find_nl(storage->string);
	}
	return (output);
}

char	*after_find_nl(t_buffer *storage, char *output)
{
	char		*tmp;
	long long	i;

	if (storage->nl == -1)
		return (output);
	tmp = (char *)malloc(sizeof(char) * (storage->nl + 1 + 1));
	if (!tmp)
	{
		free(output);
		return (0);
	}
	i = -1;
	while (++i <= storage->nl)
		tmp[i] = storage->string[i];
	tmp[i] = 0;
	output = ft_strjoin_free(output, tmp, i);
	free(tmp);
	if (!output)
		return (0);
	storage->len = storage->len - find_nl(storage->string) - 1;
	ft_memmove(storage->string, storage->string + find_nl(storage->string) + 1,
		BUFFER_SIZE - find_nl(storage->string));
	storage->nl = find_nl(storage->string);
	return (output);
}

char	*get_next_line(int fd)
{
	static t_buffer	storage;
	t_buffer		*tmp;
	char			*output;

	tmp = check_fd_storage(fd, &storage);
	if (!tmp)
		return (0);
	output = (char *)malloc(sizeof(char));
	if (!output)
	{
		free_storage(fd, tmp, &storage);
		return (0);
	}
	output[0] = 0;
	output = make_line_until_nl(fd, tmp, output);
	if (!output)
	{
		free_storage(fd, tmp, &storage);
		return (0);
	}
	output = after_find_nl(tmp, output);
	if (!output)
		free_storage(fd, tmp, &storage);
	return (output);
}

/*
#include<stdio.h>
#include<fcntl.h>
#include<time.h>
int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *line1;
	char *line2;
	clock_t start, end;
	start = clock();
	do
	{
		line1 = get_next_line(fd1);
		printf("1:%s", line1);
		line2 = get_next_line(fd2);
		printf("2:%s", line2);
		free(line1);
		free(line2);
		printf("\n");
	} while(line1 || line2);
	end = clock();
	double res = (double)(end - start)/CLOCKS_PER_SEC;
	printf("\ntime:%f\n", res);
}
*/