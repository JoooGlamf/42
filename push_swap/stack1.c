/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:48:57 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 15:18:09 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*output;

	output = (t_stack *)malloc(sizeof(t_stack));
	if (!output)
		err_exit(1, "Error\n");
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
	if (!new)
		err_exit(1, "Error\n");
	new->elem = number;
	if (stack->count == 0)
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
	if (!new)
		err_exit(1, "Error\n");
	new->elem = number;
	if (stack->count == 0)
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
