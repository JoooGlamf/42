/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:49:25 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 16:06:06 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_b_except3(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->count > 3)
		pb(stack_b, stack_a);
}

void	sort_3(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a->count < 2)
		exit(0);
	a = stack_a->head->elem;
	b = stack_a->head->next->elem;
	if (stack_a->count < 3)
	{
		if (a > b)
			sa(stack_a);
		exit(0);
	}
	c = stack_a->head->next->next->elem;
	if (b > a && b > c && c > a)
		sa(stack_a);
	else if (c > a && c > b && a > b)
		sa(stack_a);
	else if (a > b && a > c && b > c)
		sa(stack_a);
}

void	make_smallest_head(t_stack *stack_a)
{
	int	i;

	i = 0;
	find_smallest(stack_a);
	if (stack_a->smallest > stack_a->count / 2)
	{
		while (i < (stack_a->count - stack_a->smallest))
		{
			rra(stack_a);
			++i;
		}
	}
	else
	{
		while (i < stack_a->smallest)
		{
			ra(stack_a);
			++i;
		}
	}
}

void	execute_commands(t_stack *stack_a, t_stack *stack_b,
			t_info *command_info)
{
	int	i;

	i = 0;
	while (i++ < command_info->ra)
		ra(stack_a);
	i = 0;
	while (i++ < command_info->rb)
		rb(stack_b);
	i = 0;
	while (i++ < command_info->rra)
		rra(stack_a);
	i = 0;
	while (i++ < command_info->rrb)
		rrb(stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b, t_info *command_info)
{
	push_b_except3(stack_a, stack_b);
	sort_3(stack_a);
	while (stack_b->count > 0)
	{
		find_smallest_command_number(stack_a, stack_b, command_info);
		execute_commands(stack_a, stack_b, command_info);
		pa(stack_a, stack_b);
		reset_command_info(command_info);
	}
	find_smallest(stack_a);
	make_smallest_head(stack_a);
}
