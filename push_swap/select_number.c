/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:39:02 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 10:30:42 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_a에서 가장 작은 수를 찾는다. 정말로 그냥 가장 작은 정수
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

//stack->smallest를 이용하여 가장 작은 수부터 큰수까지 수를 비교하여 알맞은 위치를 찾아, 명령어의 숫자를 구한다.
int	count_command_a(t_stack *stack_a, int number)
{
	t_node	*temp;
	int		i;

	find_smallest(stack_a);
	temp = stack_a->head;
	i = 0;
	while (i < stack_a->smallest)
	{
		temp = temp->next;
		++i;
	}
	while (1)
	{
		if (number > temp->elem)
		{
			if (temp->elem > temp->next->elem)
			{
				++i;
				break ;
			}
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

int	count_command(t_stack *stack_b, int a_command_count,
		int i)
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

void	smallest_command_info(t_stack *stack_b, int a_command_count, int i, t_info *command_info)
{
	if (a_command_count >= 0 && i < (stack_b->count / 2))
	{
		command_info->ra = a_command_count;
		command_info->rb = i;
	}
	else if (a_command_count >= 0 && i >= (stack_b->count / 2))
	{
		command_info->ra = a_command_count;
		command_info->rrb = stack_b->count - i - 1;
	}
	else if (a_command_count < 0 && i < (stack_b->count / 2))
	{
		command_info->rra = a_command_count * (-1);
		command_info->rb = i;
	}
	else if (a_command_count < 0 && i >= (stack_b->count / 2))
	{
		command_info->rra = a_command_count * (-1);
		command_info->rrb = stack_b->count - i - 1;
	}
}

int	find_smallest_command_number(t_stack *stack_a,
		t_stack *stack_b, t_info *command_info)
{
	t_node	*temp;
	int		i;
	int		count;
	int		smallest_count;

	temp = stack_b->head;
	smallest_count = count_command(stack_b,
			count_command_a(stack_a, temp->elem), 0);
	temp = temp->next;
	i = 1;
	while (i < stack_b->count)
	{
		reset_command_info(command_info);
		count = count_command(stack_b,
				count_command_a(stack_a, temp->elem), i);
		if (smallest_count > count)
		{
			smallest_count = count;
			stack_b->smallest = i;
		}
		temp = temp->next;
		++i;
	}
	temp = stack_b->head;
	i = 0;
	while(i < stack_b->smallest)
		temp = temp->next;
	smallest_command_info(stack_b,
		count_command_a(stack_a, temp->elem), stack_b->smallest, command_info);
	return (stack_b->smallest);
}
