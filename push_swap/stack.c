/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:48:57 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/19 16:02:45 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*output;
	t_node	*head;
	t_node	*tail;

	head = (t_node *)malloc(sizeof(t_node));
	tail = (t_node *)malloc(sizeof(t_node));
	head->elem = 0;
	head->flag = 1;
	head->prev = 0;
	head->next = tail;
	tail->elem = 0;
	tail->flag = 1;
	tail->prev = head;
	tail->next = 0;
	output = (t_stack *)malloc(sizeof(t_stack));
	output->head = head;
	output->tail = tail;
	return (output);
}

void	push(t_stack *stack, int new_elem)
{
	t_node	*new;
	t_node	*temp;

	new = (t_node *)malloc(sizeof(t_node));
	temp = stack->head->next;
	temp->prev = new;
	stack->head->next = new;
	new->flag = 0;
	new->prev = stack->head;
	new->next = temp;
	new->elem = new_elem;
}

void	push_back(t_stack *stack, int new_elem)
{
	t_node	*new;
	t_node	*temp;

	new = (t_node *)malloc(sizeof(t_node));
	temp = stack->tail->prev;
	temp->next = new;
	stack->tail->prev = new;
	new->flag = 0;
	new->prev = temp;
	new->next = stack->tail;
	new->elem = new_elem;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		output;

	output = 0;
	if (stack->head->next != stack->tail)
	{
		temp = stack->head->next;
		stack->head->next = stack->head->next->next;
		temp->next->prev = stack->head;
		output = temp->elem;
		free(temp);
	}
	return (output);
}

int	pop_back(t_stack *stack)
{
	t_node	*temp;
	int		output;

	output = 0;
	if (stack->tail->prev != stack->head)
	{
		temp = stack->tail->prev;
		stack->tail->prev = stack->tail->prev->prev;
		temp->prev->next = stack->tail;
		output = temp->elem;
		free(temp);
	}
	return (output);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*temptemp;

	temp = stack->head;
	while (temp)
	{
		temptemp = temp;
		temp = temp->next;
		free(temptemp);
	}
	free(stack);
}
