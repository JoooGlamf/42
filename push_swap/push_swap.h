/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:05 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/21 04:28:34 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"

typedef	struct s_info
{
	int	stack_a_count;
	int	stack_b_count;
}	t_info;

typedef struct s_node
{
	int				elem;
	int				flag;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

//stack.c
t_stack	*init_stack(void);
void	push(t_stack *stack, int new_elem);
void	push_back(t_stack *stack, int new_elem);
int		pop(t_stack *stack);
int		pop_back(t_stack *stack);
void	free_stack(t_stack *stack);

//command.c
void	command_swap(t_stack *stack);
void	command_push(t_stack *stack1, t_stack *stack2);
void	command_rotate(t_stack *stack);
void	command_reverse_rotate(t_stack *stack);

//check.c
void	err_exit(int exit_code, char *string);
void	check_argc(int argc);
void	check_int(char *number);
void	check_duplication(t_stack *stack);

#endif
