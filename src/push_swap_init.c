/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:36:03 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 15:54:18 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	copy_stack(t_stack *stack)
{
	t_stack	tmp_stack;
	t_stack	new_stack;
	int		i;

	tmp_stack.size = 0;
	tmp_stack.top = NULL;
	new_stack.size = 0;
	new_stack.top = NULL;
	i = 0;
	while (i < stack->size)
	{
		push(&tmp_stack, new_node(stack->top->data), 0);
		i++;
		stack->top = stack->top->next;
	}
	i = 0;
	while (i < tmp_stack.size)
	{
		push(&new_stack, new_node(tmp_stack.top->data), 0);
		i++;
		tmp_stack.top = tmp_stack.top->next;
	}
	free_stack(&tmp_stack);
	return (new_stack);
}

t_utils	push_swap_init(t_stack *a, t_stack *b)
{
	t_utils	utils;
	t_utils	t;
	t_stack	at;

	init_utils(&utils);
	init_utils(&t);
	at = copy_stack(a);
	while (at.size--)
	{
		count_moves(at.top->data, a, &utils);
		count_moves(find_match_number(at.top->data, b, 0), b, &utils);
		sum_rr_rrr(&utils);
		if (sum_moves(&t) == 0 || sum_moves(&utils) < sum_moves(&t))
		{
			t = utils;
			if (sum_moves(&utils) == 0 || sum_moves(&utils) == 1)
				break ;
		}
		init_utils(&utils);
		at.top = at.top->next;
	}
	free_stack(&at);
	return (t);
}

int	sum_moves(t_utils *u)
{
	int	sum;

	sum = 0;
	if (u->a_rotate)
		sum += u->a_rotate;
	if (u->b_rotate)
		sum += u->b_rotate;
	if (u->a_reverse_rotate)
		sum += u->a_reverse_rotate;
	if (u->b_reverse_rotate)
		sum += u->b_reverse_rotate;
	if (u->rr)
		sum += u->rr;
	if (u->rrr)
		sum += u->rrr;
	return (sum);
}

void	count_moves(int data, t_stack *stack, t_utils *utils)
{
	int	index_node;
	int	middle_index;

	index_node = find_index(data, *stack);
	middle_index = stack->size / 2;
	if (stack->charac == 'a')
		utils->a_data = data;
	else if (stack->charac == 'b')
		utils->b_data = data;
	if (index_node == middle_index || index_node <= middle_index)
	{
		if (stack->charac == 'a')
			utils->a_rotate = index_node;
		else if (stack->charac == 'b')
			utils->b_rotate = index_node;
	}
	else
	{
		if (stack->charac == 'a')
			utils->a_reverse_rotate = stack->size - index_node;
		else if (stack->charac == 'b')
			utils->b_reverse_rotate = stack->size - index_node;
	}
}
