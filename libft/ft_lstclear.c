/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:33:06 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/08 15:55:54 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		t_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t_lst;
	}
	*lst = 0;
}
