/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:29:20 by soojoo            #+#    #+#             */
/*   Updated: 2023/02/20 20:45:41 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_buffer
{
	int				fd;
	char			string[BUFFER_SIZE + 1];
	long long		len;
	long long		nl;
	struct s_buffer	*next;
}	t_buffer;

//get_next_line_bonus.c
t_buffer	*find_right_storage(int fd, t_buffer *storage);
t_buffer	*check_fd_storage(int fd, t_buffer *storage);
char		*make_line_until_nl(int fd, t_buffer *storage, char *output);
char		*after_find_nl(t_buffer *storage, char *output);
char		*get_next_line(int fd);
//get_next_line_utils_bonus.c
void		free_storage(int fd, t_buffer *tmp, t_buffer *storage);
long long	find_nl(char *string);
char		*ft_strjoin_free(char *s1, char *s2, size_t s2_len);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);

#endif
