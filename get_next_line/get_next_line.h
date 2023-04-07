/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:22:10 by soojoo            #+#    #+#             */
/*   Updated: 2023/02/20 20:10:34 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_buffer
{
	char		string[BUFFER_SIZE + 1];
	long long	len;
	long long	nl;
}	t_buffer;

//get_next_line.c
int			check_fd_storage(int fd, t_buffer *storage);
char		*make_line_until_nl(int fd, t_buffer *storage, char *output);
char		*after_find_nl(t_buffer *storage, char *output);
char		*get_next_line(int fd);
//get_next_line_utils.c
long long	find_nl(char *string);
char		*ft_strjoin_free(char *s1, char *s2, size_t s2_len);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);

#endif
