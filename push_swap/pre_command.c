/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:43:31 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/22 17:36:51 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	command_swap(t_stack *stack)
{
	int	temp1;
	int	temp2;

	if (stack->count < 2)
		return (0);
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(stack, temp1);
	push(stack, temp2);
	return (1);
}

int	command_push(t_stack *stack1, t_stack *stack2)
{
	int		temp;

	if (stack2->count < 1)
		return (0);
	temp = pop(stack2);
	push(stack1, temp);
	stack1->count += 1;
	stack2->count -= 1;
	return (1);
}

int	command_rotate(t_stack *stack)
{
	int	temp;

	if(stack->count < 2)
		return (0);
	temp = pop(stack);
	push_back(stack, temp);
	return (1);
}

int	command_reverse_rotate(t_stack *stack)
{
	int	temp;

	if(stack->count < 2)
		return (0);
	temp = pop_back(stack);
	push(stack, temp);
	return (1);
}
