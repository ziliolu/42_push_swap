/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:34:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 11:35:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	reverse_rotate(t_stack *stack, bool op)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->prev;
		if (op)
			printf("rr%c\n", stack->charac);
		return (1);
	}
	return (-1);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		printf("rrr\n");
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
		return (1);
	}
	return (-1);
}
