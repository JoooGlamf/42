/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:10:20 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 15:21:44 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"ft_printf/ft_printf.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*output;

	output = (t_stacks *)malloc(sizeof(t_stacks));
	output->stack_a = init_stack();
	output->stack_b = init_stack();
	return (output);
}

void	push_all(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers[0])
			err_exit(1, "Error");
		j = 0;
		while (numbers[j])
		{
			check_int(numbers[j]);
			push_back(stack, ft_atoi(numbers[j]));
			j++;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_info		info;

	check_argc(argc);
	stacks = init_stacks();
	push_all(argc, argv, stacks->stack_a);
	check_duplication(stacks->stack_a);
	t_node	*temp = stacks->stack_a->head;
	while(temp)
	{
		ft_printf("%d ", temp->elem);
		temp = temp->next;
	}
}

//argc = 1이면, 입력된 값 없음, 프로그램 그대로 종료
//숫자가 아닌 문자 있으면 오류처리, 프로그램 종료
//숫자가 중복되면 오류처리, 프로그램 종료
//adt를 꼭 스택 그 자체로 만들 필요는 없는듯
//적절한 정렬 알고리즘을 찾아서 해당 정렬 알고리즘과 같이 작동하도록 명령어 셋을 사용한다?
