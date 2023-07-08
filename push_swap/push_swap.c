/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:10:20 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/04 21:10:38 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    err_name(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            if(argv[i][j] < '0' || argv[i][j] >'9')
            {
                exit(1);
            }
            ++j;
        }
        ++i;
    }
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	str_int;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		++i;
	if (str[i] == '-')
	{	
		minus *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	str_int = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		str_int = str_int * 10 + str[i] - '0';
		i++;
	}
	str_int *= minus;
	return (str_int);
}

void push_all(int argc, char **argv, t_stack *stack)
{
    t_stack *temp_stack;
    int     i;
    int     num;

    temp_stack = stack;
    i = 1;
    while(i < argc)
    {
        temp_stack->next = (t_stack *)malloc(sizeof(stack));
        temp_stack->next->elem = ft_atoi(argv[i]);
        temp_stack->next->next = 0;
        temp_stack = temp_stack->next;
        ++i;
    }
}

#include<stdio.h>
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    err_name(argc, argv);
    a = init_stack();
    b = init_stack();
    push_all(argc, argv, a);

    command_swap(a);
    push(b, 777);
    command_push(a, b);
	command_rotate(a);
	command_reverse_rotate(a);
    t_stack *temp_a = a->next;
    while(temp_a)
    {
        printf("%d\n", temp_a->elem);
        temp_a = temp_a->next;    
    }
}

//argc = 1이면, 입력된 값 없음, 프로그램 그대로 종료
//숫자가 아닌 문자 있으면 오류처리, 프로그램 종료
//숫자가 중복되면 오류처리, 프로그램 종료
//adt를 꼭 스택 그 자체로 만들 필요는 없는듯
//적절한 정렬 알고리즘을 찾아서 해당 정렬 알고리즘과 같이 작동하도록 명령어 셋을 사용한다?
