/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:17:47 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/22 11:33:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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


// ====== utils =====
t_node      *newNode(int data);
t_node      *find_last_node(t_stack stack);
int         add_node_front(t_stack *stack, t_node *newNode);

// ====== init structs =====
void        init_structs(t_stack *a, t_stack *b);

// ====== push ======
int         push(t_stack *origin, t_stack *dest);

// ====== swap ======
int         swap(t_stack *stack);

// ====== rotate ======
int         reverse_rotate(t_stack *stack);
int         rrr(t_stack *a, t_stack *b);

// ====== reverse_rotate ======
int         rotate(t_stack *stack);
int         rr(t_stack *a, t_stack *b);

// ====== destroy =====
void        free_stacks(t_stack *a, t_stack *b);

// ====== print_stack =====
int         print_stack(t_stack a, t_stack b);
void        print_info(t_stack stack);

// ====== panic =======
int         panic(char *str);

// ====== verify_args =====
int         verify_doubles(int argc, char **argv);
int         verify_args(int argc, char **argv);

int         verify_two_elements(t_stack stack);
#endif 
