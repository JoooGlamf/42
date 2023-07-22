/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:49:32 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 07:50:08 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	rra(t_stack *a)
{
	if (command_reverse_rotate(a))
	{
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(t_stack *b)
{
	if (command_reverse_rotate(b))
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (command_reverse_rotate(a) || command_reverse_rotate(b))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
