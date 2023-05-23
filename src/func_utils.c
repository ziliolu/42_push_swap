/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:08:46 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 18:23:20 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

t_node	*find_last_node(t_stack stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack.top;
	while (i < stack.size && node->next != stack.top)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	pop(t_stack *stack)
{
	int		tmp;
	t_node	*tmp_node;

	if (stack->size < 1 || !stack)
		return (0);
	else
	{
		tmp = stack->top->data;
		tmp_node = stack->top;
		if (stack->top->data == stack->top->next->data)
			stack->top = NULL;
		else
		{
			stack->top->prev->next = stack->top->next;
			stack->top->next->prev = stack->top->prev;
			stack->top = stack->top->next;
		}
	}
	stack->size--;
	free(tmp_node);
	return (tmp);
}

int	is_organized(t_stack stack)
{
	t_node	*tmp;
	t_node	*head;
	int		i;

	i = 0;
	head = stack.top;
	while (i < stack.size && stack.top->next != head && stack.top->next)
	{
		tmp = stack.top;
		if (stack.top->next->data < tmp->data)
			return (-1);
		stack.top = stack.top->next;
		i++;
	}
	return (1);
}
