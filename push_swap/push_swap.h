#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>
#include"ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
} t_stack;

t_stack	*init_stack();
void	push(t_stack *stack, int new_elem);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);

void	command_swap(t_stack *stack);
void	command_push(t_stack *stack1, t_stack *stack2);
void	command_rotate(t_stack *stack);
void	command_reverse_rotate(t_stack *stack);

#endif
