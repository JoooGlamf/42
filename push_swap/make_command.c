/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:38:33 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 09:26:45 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	smallest_command_info(t_stack *stack_b,
			int a_command_count, int i, t_info *command_info)
{
	reset_command_info(command_info);
	if (a_command_count >= 0 && i < (stack_b->count / 2))
		rotate_only(stack_b, a_command_count, i, command_info);
	else if (a_command_count < 0 && i >= (stack_b->count / 2))
		reverse_rotate_only(stack_b, a_command_count, i, command_info);
	else if (a_command_count >= 0 && i >= (stack_b->count / 2))
		ra_rrb(stack_b, a_command_count, i, command_info);
	else if (a_command_count < 0 && i < (stack_b->count / 2))
		rra_rb(stack_b, a_command_count, i, command_info);
	return (command_info->ra + command_info->rb + command_info->rr
		+ command_info->rra + command_info->rrb + command_info->rrr);
}

void	rotate_only(t_stack *stack_b,
			int a_command_count, int i, t_info *command_info)
{
	if (!a_command_count || !i)
	{
		command_info->ra = a_command_count;
		command_info->rb = i;
	}
	else if (a_command_count > i)
	{
		command_info->rr = i;
		command_info->ra = a_command_count - i;
	}
	else
	{
		command_info->rr = a_command_count;
		command_info->rb = i - a_command_count;
	}
}

void	reverse_rotate_only(t_stack *stack_b,
			int a_command_count, int i, t_info *command_info)
{
	if (!a_command_count || !i)
	{
		command_info->rra = a_command_count * (-1);
		command_info->rrb = stack_b->count - i;
	}
	else if (a_command_count * (-1) > stack_b->count - i)
	{
		command_info->rrr = stack_b->count - i;
		command_info->rra = a_command_count * (-1) - (stack_b->count - i);
	}
	else
	{
		command_info->rrr = a_command_count * (-1);
		command_info->rrb = stack_b->count - i - a_command_count * (-1);
	}
}

void	ra_rrb(t_stack *stack_b, int a_command_count,
			int i, t_info *command_info)
{
	command_info->ra = a_command_count;
	command_info->rrb = stack_b->count - i;
}

void	rra_rb(t_stack *stack_b, int a_command_count,
			int i, t_info *command_info)
{
	command_info->rra = a_command_count * (-1);
	command_info->rb = i;
}	
