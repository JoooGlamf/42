/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:05 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/17 19:36:50 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>
#include"ft_printf/ft_printf.h"

typedef struct s_node
{
	int				elem;
	int				flag;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
} t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
} t_stacks;

t_stack	*init_stack();
void	push(t_stack *stack, int new_elem);
void	push_back(t_stack *stack, int new_elem);
int		pop(t_stack *stack);
int		pop_back(t_stack *stack);
void	free_stack(t_stack *stack);

void	command_swap(t_stack *stack);
void	command_push(t_stack *stack1, t_stack *stack2);
void	command_rotate(t_stack *stack);
void	command_reverse_rotate(t_stack *stack);

#endif
