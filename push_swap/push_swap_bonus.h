/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:13:55 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 11:32:58 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"
# include"get_next_line/get_next_line.h"

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

typedef struct s_command_info
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_info;

//stack*.c
t_stack		*init_stack(void);
void		push(t_stack *stack, int number);
void		push_back(t_stack *stack, int number);
int			pop(t_stack *stack);
int			pop_back(t_stack *stack);

//pre_command.c
int			command_swap(t_stack *stack);
int			command_push(t_stack *stack1, t_stack *stack2);
int			command_rotate(t_stack *stack);
int			command_reverse_rotate(t_stack *stack);

//command*.c
int			sa(t_stack *a);
int			sb(t_stack *b);
int			ss(t_stack *a, t_stack *b);
int			pa(t_stack *a, t_stack *b);
int			pb(t_stack *a, t_stack *b);
int			ra(t_stack *a);
int			rb(t_stack *b);
int			rr(t_stack *a, t_stack *b);
int			rra(t_stack *a);
int			rrb(t_stack *b);
int			rrr(t_stack *a, t_stack *b);

//check.c
void		err_exit(int exit_code, char *string);
void		check_only_number(char *number);
void		check_int(char *number);
void		check_duplication(t_stack *stack);
int			check_align(t_stack *stack);

//sort.c
void		push_b_except3(t_stack *stack_a, t_stack *stack_b);
void		sort_3(t_stack *stack_a);
void		make_smallest_head(t_stack *stack_a);
void		execute_commands(t_stack *stack_a,
				t_stack *stack_b, t_info *command_info);
void		sort(t_stack *stack_a, t_stack *stack_b, t_info *command_info);

//select_number.c
int			find_smallest(t_stack *stack);
int			count_command_a(t_stack *stack_a, int number);
int			cound_command(t_stack *stack_b, int a_command_count, int i);
int			find_smallest_command_number(t_stack *stack_a,
				t_stack *stack_b, t_info *command_info);

//make_command.c
int			smallest_command_info(t_stack *b,
				int a_command_count, int i, t_info *command_info);
void		rotate_only(t_stack *stack_b,
				int a_command_count, int i, t_info *command_info);
void		reverse_rotate_only(t_stack *stack_b,
				int a_command_count, int i, t_info *command_info);
void		ra_rrb(t_stack *stack_b, int a_command_count,
				int i, t_info *command_info);
void		rra_rb(t_stack *stack_b, int a_command_count,
				int i, t_info *command_info);

#endif
