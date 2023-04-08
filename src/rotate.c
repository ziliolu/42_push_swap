/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:35:07 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 11:36:03 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_stack *stack, bool op)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->next;
		if (op == 1)
			ft_printf("r%c\n", stack->charac);
		return (1);
	}
	return (-1);
}

int	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		ft_printf("rr\n");
		rotate(a, 0);
		rotate(b, 0);
		return (1);
	}
	return (-1);
}
