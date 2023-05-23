/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:52:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/13 12:59:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	char			charac;
}				t_stack;

typedef struct s_utils
{
	int	a_data;
	int	b_data;
	int	a_rotate;
	int	b_rotate;
	int	a_reverse_rotate;
	int	b_reverse_rotate;
	int	rr;
	int	rrr;
}				t_utils;

// ==== algorithm.c ====
int			execute(t_stack *a, t_stack *b);
void		move_from_b_to_a(t_stack *a, t_stack *b, t_utils utils);
int			verify_sorts(t_stack *a, t_stack *b);
void		final_organization(t_stack *a, t_stack *b);
void		organize_stack_a(t_utils *utils, t_stack *a, t_stack *b);

// ==== find_specific numbers ====
int			find_highest_number(t_stack *stack);
int			find_lowest_number(t_stack *b);
int			find_match_number(int data, t_stack *stack, bool perfect_match);
int			find_perfect_match(int data, t_stack *stack);

// ==== func_utils ====
t_node		*new_node(int data);
t_node		*find_last_node(t_stack stack);
int			pop(t_stack *stack);
int			is_organized(t_stack stack);

// ==== index ====
int			find_index(int data, t_stack stack);

// ==== init_structs ====
void		init_structs(t_stack *a, t_stack *b);
t_utils		*init_utils(t_utils *utils);

// ==== panic ====
int			panic(t_stack *a, t_stack *b);
int			free_stack(t_stack *stack);

// ==== print_stacks ====
int			print_stack(t_stack *a, t_stack *b);
void		print_info(t_stack stack);
void		print_utils(t_utils *utils);

// ==== push_swap_back ====
void		find_cheapest(t_stack *origin, t_stack *dest, \
t_stack *tmp, t_utils *u);
t_utils		push_swap_back(t_stack *origin, t_stack *dest);
void		push_back(t_stack *a, t_stack *b);

// ==== push_swap_init ====
t_stack		copy_stack(t_stack *stack);
t_utils		push_swap_init(t_stack *a, t_stack *b);
int			sum_moves(t_utils *u);
void		count_moves(int data, t_stack *stack, t_utils *utils);

// ==== push ====
int			push(t_stack *stack, t_node *node, bool op);

// ==== reverse_rotate ====
int			reverse_rotate(t_stack *stack, bool op);
int			rrr(t_stack *a, t_stack *b);

// ==== rotate ====
int			rotate(t_stack *stack, bool op);
int			rr(t_stack *a, t_stack *b);

// ==== run_utils ====
void		run_utils(t_utils *u, t_stack *a, t_stack *b);
void		run_reverse_rotate(t_utils *u, t_stack *a, t_stack *b);

// ==== sorts ====
int			sort3(t_stack *stack);
int			sort5(t_stack *a, t_stack *b);

// ==== sum_moves ====
void		sum_rr_rrr(t_utils *u);
void		sum_reverse_rotates(t_utils *u);
void		sum_rotates(t_utils *utils);

// ==== swap.c ====
int			swap(t_stack *stack);

// ==== verify_args ====
int			ft_is_number(char *str);
int			verify_args(int argc, char **argv, t_stack *a, t_stack *b);
int			verify_doubles(int argc, char **argv);

#endif 
