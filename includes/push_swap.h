/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:57:47 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/03 19:28:59 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_node 
{
    int data; 
    struct s_node *next;
    struct s_node *prev;
}               t_node; 

typedef struct s_stack
{
    t_node *top;
    int     size;
    char    charac;
}               t_stack;

typedef struct s_utils
{
    int a_data;
    int b_data;
    int a_rotate;
    int b_rotate;
    int a_reverse_rotate;
    int b_reverse_rotate;
    int rr;
    int rrr;
}               t_utils;


// ====== utils =====
t_node      *newNode(int data);
t_node      *find_last_node(t_stack stack);
int         add_node_front(t_stack *stack, t_node *newNode);
int pop(t_stack *stack);

// ====== init structs =====
void        init_structs(t_stack *a, t_stack *b);
void init_utils(t_utils *utils);

// ====== push ======
int         push(t_stack *origin, t_node *node, bool op);

// ====== swap ======
int         swap(t_stack *stack);

// ====== rotate ======
int         reverse_rotate(t_stack *stack, bool op);
int         rrr(t_stack *a, t_stack *b);

// ====== reverse_rotate ======
int         rotate(t_stack *stack, bool op);
int         rr(t_stack *a, t_stack *b);

// ====== destroy =====
void        free_stacks(t_stack *a, t_stack *b);

// ====== print_stack =====
int         print_stack(t_stack *a, t_stack *b);
void        print_info(t_stack stack);
void        print_utils(t_utils *utils);

// ====== panic =======
int         panic(char *str);

// ====== verify_args =====
int         verify_doubles(int argc, char **argv);
int         verify_args(int argc, char **argv);

// ====== algorithm ======
void        execute(t_stack *a, t_stack *b);
int         is_organized(t_stack stack);
void        sum_rr_rrr(t_utils *utils);

// ====== index ======
// int         find_index(t_stack stack, t_node *node);
int         find_index(int data, t_stack stack);

// ====== push_swap ======
t_utils     push_swap_init(t_stack *a, t_stack *b);
void count_moves(int data, t_stack *stack, t_utils *utils);
int sum_moves(t_utils *utils);

int sort3(t_stack *stack);
#endif 
