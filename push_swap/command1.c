/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:07:09 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 07:50:59 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sa(t_stack *a)
{
	if (command_swap(a))
	{
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(t_stack *b)
{
	if (command_swap(b))
	{
		ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ss(t_stack *a, t_stack *b)
{
	if (command_swap(a) || command_swap(b))
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}

int	pa(t_stack *a, t_stack *b)
{
	if (command_push(a, b))
	{
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_stack *b, t_stack *a)
{
	if (command_push(b, a))
	{
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
