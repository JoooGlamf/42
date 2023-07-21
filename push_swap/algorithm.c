/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:49:25 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 04:54:58 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stack_a에 3개만 남기고 모두 stack_b로 push, stack_a 정렬
void	push_b_all(t_stack stack_a, t_stack stack_b)
{
	
}

//실제 명령 실행
void	sort(t_stack stack_a, t_stack stack_b)
{
	 int	count;
	 t_node	temp;

	 count = 0;
	 temp = stack_a->head;
	 while(temp)
	 {
		++count;
		temp = temp->next;
	 }
	 count -= 2;
	 
}

//stack_b를 모두 순회하며 각 숫자를 stack_a로 이동시키고 정렬하는데 필요한 명령어 수를 비교한다.
int	select_number(t_stack a, t_stack b)
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

int	count_command(t_stack a, t_stack b, number)
{
	t_node	temp;

	temp = t_stack->head
}

/*
int	recursive(t_stack a, t_stack b, )
{
	int		check;
	int		count;
	t_node	temp;

	check = 1;
	count = 0;
	temp = a->head;
	while(temp)
	{
		if(temp->flag == 0)
		{
			
		}
	}
	if(check)
		return (1);
	return (1 + recursive(a, b, pa);
}
*/

//재귀를 사용]
//	재귀 종료 조건: stack_a에 해당 노드 정렬 완료
//	재귀 계산(?): 명령어를 실행
//	
//	우선 stack_a에는 3개의 노드만 놔둔 뒤 모두 push_b
//
//	stack_a: 1 3 4 2 5
//	stack_b:
//	
//	stack_a: 4 2 5
//	stack_b: 3 1
//
//	stack_a: 2 4 5

//	stack_b: 
