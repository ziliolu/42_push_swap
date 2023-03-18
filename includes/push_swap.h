<<<<<<< HEAD
#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H 

#include <stdio.h>
#include <stdlib.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:17:47 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/17 22:21:03 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node 
{
    int data;    
    struct s_node *next;
    struct s_node *prev; 
}               t_node; 

typedef struct s_stack
{
    t_node *tmp;
    t_node *top;
    char    charac;
}               t_stack;

#endif 
=======

>>>>>>> 741f7f0e3cd608aa4e764f00804a3c08859b832d
