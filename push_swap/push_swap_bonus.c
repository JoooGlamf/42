/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:27:45 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 11:32:30 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*command_input;

	if(argc < 2)
		exit(0);
	stacks = init_stacks();
	push_all(argc, argv, stacks->stack_a);
	check_duplication(stacks->stack_a);
	if(check_align(stacks->stack_a))
		exit(0);
	command_input = get_next_line(0);
	while(command_input)
	{
		if(!ft_strncmp(command_input,"sa\n", 3))
			sa(stacks->stack_a);
		else if(!ft_strncmp(command_input,"sb\n", 3))
			sb(stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			ss(stacks->stack_a, stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			pa(stacks->stack_a, stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			pb(stacks->stack_b, stacks->stack_a);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			ra(stacks->stack_a);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			rb(stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			rr(stacks->stack_a, stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			rra(stacks->stack_a);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			rrb(stacks->stack_b);
		else if(!ft_strncmp(command_input,"ss\n", 3))
			rrr(stacks->stack_a, stacks->stack_b);
		else
			err_exit(1, "Error\n");
		free(command_input);
		command_input = get_next_line(0);
	}
	free(command_input);
	if(check_align(stacks->stack_a) && !(stacks->stack_b->head))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
