
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:20:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/17 23:06:01 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>


// void push(int data, t_stack *stack)
// {
//     t_node *node;
//     node = malloc(sizeof(node));
    
//     node->data = data;
//     node->next = NULL;

//     *(node->next) = stack->top;
//     stack->top = *node;
// }


t_node *newNode(int data)
{
    t_node *node;
    
    node = malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    
    return (node);
}


// void array_into_list(t_stack *stack, int *array)
// {
//     int i;

//     i = 0;
//     while(array[i])
//     {
        
//     }
// }

t_node *find_last_node(t_stack stack)
{
    while(stack.top->next) // p/ nao deixar acessar o null
        stack.top = stack.top->next;
    return(stack.top);
}

int add_node_front(t_stack *stack, t_node *newNode)
{
    t_node *last;
    t_node *tmp;
    
    if(!stack->top)
    {
        stack->top = newNode;
        stack->top->next = NULL;
        stack->top->prev = NULL;      
        return (1);
    }
    last = find_last_node(*stack);
    
    if(last->next == NULL)
        printf("null");
        
    newNode->next = stack->top;
    newNode->prev = last;
    stack->top->prev = newNode;
    stack->top = newNode;
    
    return (1);
}

int push(t_stack *origin, t_stack *dest)
{
    t_node *tmp;

    printf("PUSH %c\n", dest->charac);
    
    if(!origin->top)
    {
        printf("-> não há elementos suficientes p/ push");
        return(-1);
    }    
    
    tmp = origin->top;    
    origin->top = origin->top->next;
    add_node_front(dest, tmp);
    return(1);
}

int swap(t_stack *stack)
{
    t_node *tmp;
    
    printf("SWAP %c\n", stack->charac);
    if(!stack->top || !stack->top->next)
    {
        printf("-> não há elementos suficientes p/ swap\n");
        return(-1);
    }
    tmp = stack->top;
    stack->top = stack->top->next;
    tmp->next = stack->top->next;
    stack->top->next = tmp;         
}

int rotate(t_stack *stack)
{
    t_node *last_node;
    
    printf("ROTATE %c\n", stack->charac);
    if (!stack->top || !stack->top->next) // verificar se há no minimo dois elementos
    {
        printf("-> não há elementos suficientes p/ rotate\n");
        return (-1);
    }
}

int print_stack(t_stack a, t_stack b) //nao utilizar * para poder criar apenas copia
{
    printf("== a ==\n");
    while(a.top)
    {
        printf("  %d   \n", a.top->data);
        a.top = a.top->next;
    }
    printf("== b ==\n");
    while(b.top)
    {
        printf("  %d   \n", b.top->data);
        b.top = b.top->next;
    }
    printf("=======\n\n");
    return (1);
}

void free_stacks(t_stack *a, t_stack *b)
{
    t_node *tmp;
    while(a->top)
    {
        tmp = a->top; 
        a->top = a->top->next;
        free(tmp);
    }
    while(b->top)
    {
        tmp = b->top;
        b->top = b->top->next;
        free(tmp);
    }
}



int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i; 

    
    a.top = NULL;
    b.top = NULL;
    a.charac = 'a';
    b.charac = 'b';
    i = 1;
    
    print_stack(a, b);
    while(--argc >= i)
        add_node_front(&a, newNode(atoi(argv[argc])));
    
    print_stack(a, b);
    printf("top: %d\n", a.top->data);
    printf("prev do primeiro numero: %d\n", a.top->prev->data);
    printf("next do primeiro numero: %d\n\n", a.top->next->data);
    
    printf("prev do segundo numero: %d\n", a.top->next->prev->data);
    printf("next do segundo numero: %d\n\n", a.top->next->next->data);
    
    printf("prev do último numero: %d\n", find_last_node(a)->prev->data);
    if(find_last_node(a)->next == NULL)
        printf("oi\n");
    
    printf("prev do último numero: %d\n\n", find_last_node(a)->next->data);
    free_stacks(&a, &b);
}       
>>>>>>> 741f7f0e3cd608aa4e764f00804a3c08859b832d
