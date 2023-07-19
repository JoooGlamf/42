/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:10:20 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/19 13:57:49 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"ft_printf/ft_printf.h"

void    check_argv(int argc, char **argv)
{
    int i;
    int j;

	if(argc < 2)
	{
		ft_printf("No arguments\n");
		exit(0);
	}
    i = 1;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
			if(argv[i][j] == '-')
			{
				if(j == 0)
				{
					if(argv[i][j + 1] < '0' || argv[i][j] > '9')
					{
						ft_printf("Error1\n");
						exit(1);
					}
				}
				else
				{
					if(argv[i][j - 1] != ' ' || argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
					{
						ft_printf("Error\n");
						exit(1);
					}
				}
			}
            if((argv[i][j] < '0' || argv[i][j] >'9') && argv[i][j] != ' ' && argv[i][j] != '-')
            {
				ft_printf("Error\n");
                exit(1);
            }
            ++j;
        }
        ++i;
    }
}

void	check_int(char *number)
{
	if(number[0] == '-')
	{
		if(ft_strlen(number) > 11)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if(ft_strncmp(number, "-2147483648", 11) > 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	else
	{
		if(ft_strlen(number) > 10)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if(ft_strncmp(number, "2147483647", 10) > 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}

void push_all(int argc, char **argv, t_stack *stack)
{
    int     i;
	int		j;
	char	**numbers;

    i = 1;
    while(i < argc)
    {
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while(numbers[j])
		{
			check_int(numbers[j]);
			push(stack, ft_atoi(numbers[j]));
			j++;
		}
		++i;
    }
}

void	check_duplication(t_stack *stack)
{
	t_node	*temp;
	t_node	*temptemp;

	temp = stack->head->next;
	while(temp->flag == 0)
	{
		temptemp = stack->head->next;
		while(temptemp != temp)
		{
			if(temptemp->elem == temp->elem)
				exit(1);
			temptemp = temptemp->next;
		}
		temp = temp->next;
	}
}

#include<stdio.h>
int main(int argc, char **argv)
{
	t_stacks	*stacks;

	check_argv(argc, argv);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = init_stack();
	stacks->stack_b = init_stack();
	push_all(argc, argv, stacks->stack_a);
	check_duplication(stacks->stack_a);
}

//argc = 1이면, 입력된 값 없음, 프로그램 그대로 종료
//숫자가 아닌 문자 있으면 오류처리, 프로그램 종료
//숫자가 중복되면 오류처리, 프로그램 종료
//adt를 꼭 스택 그 자체로 만들 필요는 없는듯
//적절한 정렬 알고리즘을 찾아서 해당 정렬 알고리즘과 같이 작동하도록 명령어 셋을 사용한다?
