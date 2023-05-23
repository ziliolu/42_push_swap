/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specific_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:49:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/13 10:23:35 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_highest_number(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = find_lowest_number(stack);
	if (!stack->top || !stack)
		return (0);
	while (i < stack->size)
	{
		if (stack->top->data > max)
			max = stack->top->data;
		stack->top = stack->top->next;
		i++;
	}
	return (max);
}

int	find_lowest_number(t_stack *b)
{
	int	i;
	int	min;

	i = 0;
	min = b->top->data;
	while (i < b->size)
	{
		if (b->top->data < min)
			min = b->top->data;
		b->top = b->top->next;
		i++;
	}
	return (min);
}

int	find_match_number(int data, t_stack *stack, bool perfect_match)
{
	int	i;
	int	match;

	i = 0;
	match = find_lowest_number(stack);
	if (data > find_highest_number(stack))
		return (find_highest_number(stack));
	else if (data < find_lowest_number(stack) && perfect_match == 0)
		return (find_highest_number(stack));
	else
	{
		while (i < stack->size)
		{
			if (stack->top->data < data && stack->top->data > match)
				match = stack->top->data;
			stack->top = stack->top->next;
			i++;
		}
	}
	return (match);
}

int	find_perfect_match(int data, t_stack *stack)
{
	int	i;
	int	match;

	i = 0;
	match = find_highest_number(stack);
	if (data > find_highest_number(stack))
		return (find_lowest_number(stack));
	else
	{
		while (i < stack->size)
		{
			if (stack->top->data > data && stack->top->data < match)
				match = stack->top->data;
			stack->top = stack->top->next;
			i++;
		}
	}
	return (match);
}
