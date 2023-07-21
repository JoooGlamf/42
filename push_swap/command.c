/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:07:09 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 18:11:27 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sa(t_stack a)
{
	if(command_swap(a))
	{
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(t_stack b)
{
	if(command_swap(b))
	{
		ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ss(t_stack a, t_stack b)
{
	if(command_swap(a) && command_swap(b))
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
	
int	pa(t_stack a, t_stack b, t_info info)
{
	if(command_push(a, b))
	{
		info->a_count += 1;
		info->b_count -= 1;
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_stack b, t_stack a);
{
	if(command_push(b, a))
	{
		info->b_count += 1;
		info->a_count -= 1;
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	ra(t_stack a)
{
	if(command_rotate(a))
	{
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(t_stack b)
{
	if(command_rotate(b))
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_stack a, t_stack b)
{
	if(command_rotate(a) && command_rotate(b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}

int	rra(t_stack a)
{
	if(command_reverse_rotate(a))
	{
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(t_stack b)
{
	if(command_reverse_rotate(b))
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(t_stack a, t_stack b)
{
	if(command_reverse_rotate(a) && command_reverse_rotate(b))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
