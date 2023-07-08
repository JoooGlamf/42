/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:48:57 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/27 16:44:06 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack *init_stack()
{
    t_stack *output;

    output = (t_stack *)malloc(sizeof(t_stack));
    output->elem = 0;
    output->next = 0;
    return (output);
}

void	push(t_stack *stack, int new_elem)
{
	t_stack	*temp;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->elem = new_elem;
	new->next = 0;
	if(stack->next)
	{
		temp = stack->next;
		new->next = temp;
		stack->next = new;
	}
	else
		stack->next = new;
}

int	pop(t_stack *stack)
{
	t_stack	*temp;
	int		output;

	if(stack->next)
	{
		temp = stack->next;
		stack->next = stack->next->next;
		output = temp->elem;
		free(temp);
		return (output);
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack *temp;

	while(stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
