/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:36:24 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 15:49:30 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort3(t_stack *stack)
{
	if (is_organized(*stack) == 1)
		return (1);
	if (stack->top->data == find_highest_number(stack))
		rotate(stack, 1);
	else if (stack->top->next->data == find_highest_number(stack))
		reverse_rotate(stack, 1);
	if (stack->top->data > stack->top->next->data)
		swap(stack);
	return (1);
}

int	sort5(t_stack *a, t_stack *b)
{
	push(b, new_node(pop(a)), 1);
	push(b, new_node(pop(a)), 1);
	sort3(a);
	final_organization(a, b);
	return (1);
}
