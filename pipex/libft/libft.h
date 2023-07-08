/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:31:03 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/03 07:00:40 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void	*ft_memset(void *ptr, int value, size_t num);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
