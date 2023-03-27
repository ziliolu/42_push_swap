
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

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i; 
    i = 1;

    if(verify_args(argc, argv) == 1)
    {
        init_structs(&a, &b);
        print_stack(a, b);
        while(--argc >= i)
            push(&a, newNode(atoi(argv[argc])), 0);
        if(is_organized(a) == 1)
        {
            printf("its already organized, nothing to be done ;)");
            exit(0);
        }
        push_swap_init(&a, &b);
        printf("%d\n", is_organized(a));
        // print_stack(a, b);
        // push(&b, pop(&a), 1);
        // print_stack(a, b);
        // push(&b, pop(&a), 1);
        // print_stack(a, b);
        // push(&a, pop(&b), 1);
        // print_stack(a, b);
        // swap(&a);
        // print_stack(a, b);
        // push(&b, pop(&a), 1);
        // print_stack(a, b);
        // rr(&a, &b);
        // print_stack(a, b);
    }
    return(0);
}       
