/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:10:20 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 16:05:15 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"ft_printf/ft_printf.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*output;

	output = (t_stacks *)malloc(sizeof(t_stacks));
	if (!output)
		err_exit(1, "Error\n");
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
		if (!numbers)
			err_exit(1, "Error\n");
		j = 0;
		while (numbers[j])
		{
			check_only_number(numbers[j]);
			check_int(numbers[j]);
			push_back(stack, ft_atoi(numbers[j]));
			++(stack->count);
			free(numbers[j]);
			j++;
		}
		free(numbers[j]);
		++i;
		free(numbers);
	}
}

void	reset_command_info(t_info *command_info)
{
	command_info->ra = 0;
	command_info->rb = 0;
	command_info->rra = 0;
	command_info->rrb = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_info		*command_info;

	if (argc < 2)
		exit(0);
	stacks = init_stacks();
	command_info = (t_info *)malloc(sizeof(t_info));
	if (!command_info)
		err_exit(1, "Error\n");
	reset_command_info(command_info);
	push_all(argc, argv, stacks->stack_a);
	check_duplication(stacks->stack_a);
	check_align(stacks->stack_a);
	sort(stacks->stack_a, stacks->stack_b, command_info);
	free(command_info);
	exit(0);
}
