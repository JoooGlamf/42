/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:49:25 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/22 20:25:35 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_b_all(t_stack stack_a, t_stack stack_b, t_info *info)
{
	t_node	temp;

	temp = stack_a->head;
	while(info->a_count > 3)
		pa(stack_a);
}

void	sort_3(t_stack *stack_a, t_info *info)
{
	int	a;
	int	b;
	int	c;

	if(info->a_count < 2)
		exit(0);
	a = stack_a->head->next->elem;
	b = stack_a->head->next->next->elem;
	if(info->a_count < 3)
	{
		if(a > b)
			sa(a);
		exit(0);
	}
	c = stack_a->head->next->next->next->elem;
	if(b > a && b > c && c > a)
		sa(stack_a);
	else if(c > a && c > b && a > b)
		sa(stack_a);
	else if(a > b && a > c && b > c)
		sa(stack_a);
}

int	find_smallest(t_stack stack)
{
	int		i;
	int		smallest_number;
	t_node	temp;

	smallest_number = stack->head->elem;
	temp = stack->head;
	i = 0;
	while(i < stack->count)
	{
		if(temp->elem < stack->smallest)
		{
			smallest_number = temp->elem;
			stack->smallest = i;
		}
		temp = temp->next;
		++i;
	}
	return (stack->smallest);
}


//find_smallest까지 만들었고stack->smallest를 이용하여 가장 작은 수부터 큰수까지 수를 비교하여 알맞은 위치를 찾아, 명령어의 숫자를 구한다.
int	count_command_a(t_stack a, number)
{
	t_node	temp;
	int		count;
	int		i;

	count = 0;
	temp = a->head;
	i = 0;
	while(i < stack->smallest)
		temp = temp->next;
	i = 0;
	while(i < stack->count)
	{
		if(number > temp->elem)
		{
			++count;
			temp = temp->next;
			if(temp->elem > temp->next->elem)
				break;
		}
		break;
	}
	if(count > stack->count / 2)
		count = count - stack->count;
	return (count);
}

//stack_b를 모두 순회하며 각 숫자를 stack_a로 이동시키고 정렬하는데 필요한 명령어 수를 비교한다. 명령어를 쓸 필요 없이 알맞은 위치만 찾으면 된다.
//stack_b의 이동횟수는 i를 사용한다. i의 갯수가 절반을 넘어가면 i - stack->count하여, 음의 값(rrb)의 횟수를 구한다. 
//count_command_a와 i의 부호가 같다면, rr or rrr을 사용하여 명령어의 실행 회수를 줄여준다.
int	select_number(t_stack *stack_a, t_stack *stack_b)
{
	t_node	temp;
	int		i;
	int		smallest_count;
	int		smallest_i;

	smallest_count;
	temp = b->head;
	i = 0;
	while(i < stack_b->count)
	{
		count = i + count_command_a(stack_a, temp->elem);
		if(smallest_count > i + count_command_a(
	}
	return (number);
}

//실제 명령 실행
void	sort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	push_b_all(stack_a, stack_b, info);
	sort_3(stack_a, info);

} 
