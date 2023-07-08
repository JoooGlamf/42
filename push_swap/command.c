#include"push_swap.h"

void	command_swap(t_stack *stack)
{
	int	temp1;
	int	temp2;

	if(stack->next && stack->next->next)
	{
		temp1 = pop(stack);
		temp2 = pop(stack);
		push(stack, temp1);
		push(stack, temp2);
	}
}

void	command_push(t_stack *stack1, t_stack *stack2)
{
	int		temp;
	t_stack	*new;

	if(stack2->next)
	{
		temp = pop(stack2);
		push(stack1, temp);
	}
}

void	command_rotate(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*find_last;

	temp = stack->next;
	stack->next = stack->next->next;
	find_last = stack->next;
	while(find_last->next)
		find_last = find_last->next;
	find_last->next = temp;
	temp->next = 0;
}

void	command_reverse_rotate(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*find_last;

	temp = stack->next;
	while(temp->next->next)
		temp = temp->next;
	find_last = temp->next;
	temp->next = 0;
	temp = stack->next;
	stack->next = find_last;
	find_last->next = temp;
}
