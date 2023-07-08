/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:06:41 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 01:04:54 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	check_fd_storage(int fd, t_buffer *storage)
{
	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	if (storage->string[0] == 0)
	{
		storage->len = read(fd, storage->string, BUFFER_SIZE);
		if (storage->len == 0 || storage->len == -1)
		{
			ft_bzero(storage->string, BUFFER_SIZE + 1);
			storage->len = 0;
			storage->nl = -1;
			return (0);
		}
		storage->string[storage->len] = 0;
		storage->nl = find_nl(storage->string);
	}
	return (1);
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
	int				check;
	char			*output;

	check = check_fd_storage(fd, &storage);
	if (!check)
		return (0);
	output = (char *)malloc(sizeof(char));
	if (!output)
		return (0);
	output[0] = 0;
	output = make_line_until_nl(fd, &storage, output);
	if (!output)
		return (0);
	output = after_find_nl(&storage, output);
	if (!output)
		return (0);
	return (output);
}

//#include<fcntl.h>
//#include<stdio.h>
//#include<time.h>
//int main()
//{
//	int fd = open("test.txt", O_RDONLY);
//	clock_t start, end;
//	start = clock();
//	char *line = get_next_line(17878787);
//	//while(line)
//	//{
//	//	printf("%s",line);
//	//	free(line);
//	//	line = get_next_line(fd);
//	//}
//	//end = clock();
//	//double res = (double)(end - start)/CLOCKS_PER_SEC;
//	//printf("\ntime:%f\n", res);
//}
