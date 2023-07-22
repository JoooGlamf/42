/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:48:46 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 07:50:19 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ra(t_stack *a)
{
	if (command_rotate(a))
	{
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(t_stack *b)
{
	if (command_rotate(b))
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	if (command_rotate(a) || command_rotate(b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
