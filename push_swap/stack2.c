/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:54:51 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/23 14:44:17 by soojoo           ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	int		i;
	t_node	*temp;
	t_node	*temptemp;

	temp = stack->head;
	i = 0;
	while (temp != stack->head)
	{
		temptemp = temp;
		temp = temp->next;
		free(temptemp);
	}
	free(stack->head);
	free(stack);
}
