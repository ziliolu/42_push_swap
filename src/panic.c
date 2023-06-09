/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:28:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/13 10:41:36 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	panic(t_stack *a, t_stack *b)
{
	ft_printf ("Error\n");
	free_stack(a);
	free_stack(b);
	return (-1);
}

int	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	tmp = NULL;
	if (!stack->top || !stack)
		return (-1);
	if (stack->top != NULL)
	{
		current = stack->top->next;
		while (current != stack->top)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
	}
	free(stack->top);
	stack->top = NULL;
	return (1);
}
