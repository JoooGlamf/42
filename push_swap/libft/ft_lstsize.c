/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:17:13 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/08 15:56:19 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
