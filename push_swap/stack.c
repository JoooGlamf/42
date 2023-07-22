/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:48:57 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 03:36:00 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*output;

	output = (t_stack *)malloc(sizeof(t_stack));
	output->head = 0;
	output->tail = 0;
	output->count = 0;
	output->smallest = 0;
	return (output);
}

void	push(t_stack *stack, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->elem = number;
	if(stack->count == 0)
	{
		new->next = new;
		new->prev = new;
		stack->head = new;
		stack->tail = new;
		return ;
	}
	new->next = stack->head;
	new->prev = stack->tail;
	stack->head->prev = new;
	stack->tail->next = new;
	stack->head = new;
}

void	push_back(t_stack *stack, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->elem = number;
	if(stack->count == 0)
	{
		new->next = new;
		new->prev = new;
		stack->head = new;
		stack->tail = new;
		return ;
	}
	new->prev = stack->tail;
	new->next = stack->head;
	stack->tail->next = new;
	stack->head->prev = new;
	stack->tail = new;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		output;

	output = 0;
	if(stack->head)
	{
		output = stack->head->elem;
		stack->tail->next = stack->head->next;
		stack->head->next->prev = stack->tail;
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	return (output);
}

int	pop_back(t_stack *stack)
{
	t_node	*temp;
	int		output;

	output = 0;
	if (stack->head)
	{
		output = stack->tail->elem;
		stack->head->prev = stack->tail->prev;
		stack->tail->prev->next = stack->head;
		temp = stack->tail->prev;
		free(stack->tail);
		stack->tail = temp;
	}
	return (output);
}

void	free_stack(t_stack *stack)
{
	while(stack->head != stack->tail)
		pop(stack);
	free(stack);
}
