/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:39:02 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 16:05:59 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int		i;
	int		smallest_number;
	t_node	*temp;

	smallest_number = stack->head->elem;
	stack->smallest = 0;
	temp = stack->head->next;
	i = 1;
	while (i < stack->count)
	{
		if (temp->elem < smallest_number)
		{
			smallest_number = temp->elem;
			stack->smallest = i;
		}
		temp = temp->next;
		++i;
	}
	return (stack->smallest);
}

int	count_command_a(t_stack *stack_a, int number)
{
	t_node	*temp;
	int		i;

	temp = stack_a->head;
	i = -1;
	while (++i < stack_a->smallest)
		temp = temp->next;
	while (1)
	{
		if (number > temp->elem)
		{
			if (temp->elem > temp->next->elem && ++i)
				break ;
		}
		else
			break ;
		temp = temp->next;
		++i;
	}
	while (i >= stack_a->count)
		i -= stack_a->count;
	if (i > stack_a->count / 2)
		i = i - stack_a->count;
	return (i);
}

int	count_command(t_stack *stack_b, int a_command_count, int i)
{
	int	count;

	count = 0;
	if (a_command_count >= 0 && i < (stack_b->count / 2))
		count = a_command_count + i;
	else if (a_command_count >= 0 && i >= (stack_b->count / 2))
		count = a_command_count + stack_b->count - i;
	else if (a_command_count < 0 && i < (stack_b->count / 2))
		count = a_command_count * (-1) + i;
	else if (a_command_count < 0 && i >= (stack_b->count / 2))
		count = a_command_count * (-1) + stack_b->count - i;
	return (count);
}

void	smallest_command_info(t_stack *stack_b,
			int a_command_count, int i, t_info *command_info)
{
	if (a_command_count >= 0 && i < (stack_b->count / 2))
	{
		command_info->ra = a_command_count;
		command_info->rb = i;
	}
	else if (a_command_count >= 0 && i >= (stack_b->count / 2))
	{
		command_info->ra = a_command_count;
		command_info->rrb = stack_b->count - i;
	}
	else if (a_command_count < 0 && i < (stack_b->count / 2))
	{
		command_info->rra = a_command_count * (-1);
		command_info->rb = i;
	}
	else if (a_command_count < 0 && i >= (stack_b->count / 2))
	{
		command_info->rra = a_command_count * (-1);
		command_info->rrb = stack_b->count - i;
	}
}

int	find_smallest_command_number(t_stack *stack_a,
		t_stack *stack_b, t_info *command_info)
{
	t_node	*temp;
	int		i;
	int		a_command_count;
	int		smallest_count;

	temp = stack_b->head;
	find_smallest(stack_a);
	a_command_count = count_command_a(stack_a, temp->elem);
	smallest_count = count_command(stack_b, a_command_count, 0);
	smallest_command_info(stack_b, a_command_count, 0, command_info);
	temp = temp->next;
	i = 0;
	while (++i < stack_b->count)
	{
		a_command_count = count_command_a(stack_a, temp->elem);
		if (smallest_count > count_command(stack_b, a_command_count, i))
		{
			smallest_count = count_command(stack_b, a_command_count, i);
			stack_b->smallest = i;
			reset_command_info(command_info);
			smallest_command_info(stack_b, a_command_count, i, command_info);
		}
		temp = temp->next;
	}
	return (stack_b->smallest);
}
