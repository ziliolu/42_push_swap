/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:55:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 15:56:20 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_stack *stack, t_node *node, bool op)
{
	if (!node)
		return (-1);
	stack->size++;
	if (op == 1)
		ft_printf("p%c\n", stack->charac);
	if (!stack->top)
	{
		stack->top = node;
		stack->top->next = node;
		stack->top->prev = node;
		return (1);
	}
	node->next = stack->top;
	node->prev = stack->top->prev;
	stack->top->prev->next = node;
	stack->top->prev = node;
	stack->top = node;
	return (1);
}
