/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:54:51 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 16:09:52 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		output;

	output = 0;
	if (stack->head)
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
