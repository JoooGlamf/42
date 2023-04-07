/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:38:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/08 15:56:57 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*t_lst;

	if (!lst || !f)
		return ;
	t_lst = lst;
	while (t_lst)
	{
		f(t_lst->content);
		t_lst = t_lst->next;
	}
}
