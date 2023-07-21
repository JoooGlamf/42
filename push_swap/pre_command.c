/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:43:31 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 18:00:07 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	command_swap(t_stack *stack, char *stack_name)
{
	int	temp1;
	int	temp2;

	if (stack->head->next != stack->tail
		&& stack->head->next->next != stack->tail)
	{
		temp1 = pop(stack);
		temp2 = pop(stack);
		push(stack, temp1);
		push(stack, temp2);
		return (1);
	}
	return (0);
}

int	command_push(t_stack *stack1, t_stack *stack2)
{
	int		temp;

	if (stack2->head->next != stack2->tail)
	{
		temp = pop(stack2);
		push(stack1, temp);
		return (1);
	}
	return (0);
}

int	command_rotate(t_stack *stack)
{
	int	temp;

	if (stack->head->next != stack->tail
		&& stack->head->next->next != stack->tail)
	{
		temp = pop(stack);
		push_back(stack, temp);
		return (1);
	}
	return (0);
}

int	command_reverse_rotate(t_stack *stack)
{
	int	temp;

	if (stack->head->next != stack->tail
		&& stack->head->next->next != stack->tail)
	{
		temp = pop_back(stack);
		push(stack, temp);
		return (1);
	}
	return (0);
}
