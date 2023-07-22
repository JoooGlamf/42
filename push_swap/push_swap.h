/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:05 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/22 18:20:58 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"

typedef struct s_node
{
	int				elem;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		count;
	int		smallest;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

//stack.c
t_stack	*init_stack(void);
void	push(t_stack *stack, int number);
void	push_back(t_stack *stack, int number);
int		pop(t_stack *stack);
int		pop_back(t_stack *stack);
void	free_stack(t_stack *stack);

//pre_command.c
int	command_swap(t_stack *stack);
int	command_push(t_stack *stack1, t_stack *stack2);
int	command_rotate(t_stack *stack);
int	command_reverse_rotate(t_stack *stack);

//command.c
int	sa(t_stack *a);
int	sb(t_stack *b);
int	ss(t_stack *a, t_stack *b);
int	pa(t_stack *a, t_stack *b);
int	pb(t_stack *a, t_stack *b);
int ra(t_stack *a);
int	rb(t_stack *b);
int	rr(t_stack *a, t_stack *b);
int rra(t_stack *a);
int rrb(t_stack *b);
int rrr(t_stack *a, t_stack *b);

//check.c
void	err_exit(int exit_code, char *string);
void	check_argc(int argc);
void	check_int(char *number);
void	check_duplication(t_stack *stack);

#endif
