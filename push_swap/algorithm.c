/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:49:25 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 18:59:59 by soojoo           ###   ########.fr       */
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

int	count_command(t_stack a, t_info info, number)
{
	t_node	temp;

	temp = a->head;
	while(temp)
	{
		if(flag == 0)
		{

		}
	}
}

//stack_b를 모두 순회하며 각 숫자를 stack_a로 이동시키고 정렬하는데 필요한 명령어 수를 비교한다. 명령어를 쓸 필요 없이 알맞은 위치만 찾으면 된다.
int	select_number(t_stack *stack_a, t_stack *stack_b)
{
	t_node	temp;
	int		count;
	int		number;

	count = 0;
	temp = b->head;
	while(temp)
	{
		if(temp->flag == 0)
		{
			if(count_command(a, b) < count)
			{
				count = count_command(a, b);
				number = temp->elem;
			}
		}
	}
	return (number);
}

//실제 명령 실행
void	sort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	push_b_all(stack_a, stack_b, info);
	sort_3(stack_a, info);

} 
