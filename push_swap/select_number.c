/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:39:02 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 06:55:19 by soojoo           ###   ########.fr       */
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
	temp = stack->head->next;
	i = 1;
	while(i < stack->count)
	{
		if(temp->elem < smallest_number)
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
#include<stdio.h>
int	count_command_a(t_stack *stack_a, int number)
{
	t_node	*temp;
	int		i;

	find_smallest(stack_a);
	temp = stack_a->head;
	i = 0;
	while(i < stack_a->smallest)
	{
		temp = temp->next;
		++i;
	}
	while(1)
	{
		if(number > temp->elem)
		{
			if(temp->elem > temp->next->elem)
			{
				++i;
				break;
			}
		}
		else
		{
			break;
		}
		temp = temp->next;
		++i;
	}
	while(i >= stack_a->count)
		i -= stack_a->count;
	if(i > stack_a->count / 2)
		i = i - stack_a->count;
	return (i);
}

//stack_b를 모두 순회하며 각 숫자를 stack_a로 이동시키고 정렬하는데 필요한 명령어 수를 비교한다. 명령어를 쓸 필요 없이 알맞은 위치만 찾으면 된다.
//stack_b의 이동횟수는 i를 사용한다. i의 갯수가 절반을 넘어가면 i - stack->count하여, 음의 값(rrb)의 횟수를 구한다.
//count_command_a와 i의 부호가 같다면, rr or rrr을 사용하여 명령어의 실행 회수를 줄여준다.

int	count_command(t_stack *stack_b, int a_command_count, int i, t_command_info *command_info)
{
	int	count;

	count = 0;
	if(a_command_count < 0 && i > stack_b->count / 2)
	{
		if(a_command_count * (-1) > (stack_b->count - i))
		{
			command_info->rrr = stack_b->count - i;;
			command_info->rra = a_command_count * (-1) - command_info->rrr;
			count = a_command_count * (-1);
		}
		else
		{
			command_info->rrr = a_command_count * (-1);
			command_info->rrb = stack_b->count - i - command_info->rrr;
			count = (stack_b->count - i) * (-1);
		}
	}
	else if(a_command_count > 0 && i <= stack_b->count / 2)
	{
		if(a_command_count > i)
		{
			command_info->rr = i;
			command_info->ra = a_command_count - command_info->rr - 1;
			count = a_command_count;
		}
		else
		{
			command_info->rr = a_command_count;
			command_info->rb = i - command_info->rr;
			count = i;
		}
	}
	else
	{
		if(a_command_count > 0)
		{
			command_info->ra = a_command_count;
			command_info->rrb = stack_b->count - i;
			count = a_command_count + i;
		}
		else
		{
			command_info->rra = a_command_count * (-1);
			command_info->rb = i;
			count = a_command_count * (-1) + i;
		}
	}
	count += 1;
	return (count);
}

int	find_smallest_command_number(t_stack *stack_a, t_stack *stack_b, t_command_info *command_info)
{
	t_node	*temp;
	int		i;
	int		count;
	int		smallest_count;

	temp = stack_b->head;
	smallest_count = count_command(stack_b, count_command_a(stack_a, temp->elem), 0, command_info);
	temp = temp->next;
	i = 1;
	while(i < stack_b->count)
	{
		count = count_command(stack_b, count_command_a(stack_a, temp->elem), i, command_info);
		if(smallest_count > count)
		{
			smallest_count = count;
			stack_b->smallest = i;
		}
		temp = temp->next;
		++i;
	}
	return (stack_b->smallest);
}
