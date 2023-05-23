/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:20:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/13 12:34:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute(t_stack *a, t_stack *b)
{
	t_utils	utils;
	int		i;

	if (verify_sorts(a, b) == -1)
	{
		push(b, new_node(pop(a)), 1);
		push(b, new_node(pop(a)), 1);
		i = a->size;
		while (i > 3 && is_organized(*a) == -1)
		{
			utils = push_swap_init(a, b);
			sum_rr_rrr(&utils);
			run_utils(&utils, a, b);
			push(b, new_node(pop(a)), 1);
			i--;
		}
		sort3(a);
		move_from_b_to_a(a, b, utils);
		organize_stack_a(init_utils(&utils), a, b);
	}
	return (1);
}

void	move_from_b_to_a(t_stack *a, t_stack *b, t_utils utils)
{
	int	i;

	i = b->size;
	while (i > 0)
	{
		utils = push_swap_back(b, a);
		sum_rr_rrr(&utils);
		run_utils(&utils, a, b);
		push(a, new_node(pop(b)), 1);
		i--;
	}
}

int	verify_sorts(t_stack *a, t_stack *b)
{
	if (a->size == 2 && (is_organized(*a) == -1))
	{
		swap(a);
		return (1);
	}
	if (a->size == 3)
	{
		sort3(a);
		return (1);
	}
	if (a->size == 5)
	{
		sort5(a, b);
		return (1);
	}
	return (-1);
}

void	final_organization(t_stack *a, t_stack *b)
{
	t_utils	utils;

	while (b->size > 0)
	{
		push_back(a, b);
	}
	organize_stack_a(init_utils(&utils), a, b);
}

void	organize_stack_a(t_utils *utils, t_stack *a, t_stack *b)
{
	count_moves(find_lowest_number(a), a, utils);
	run_utils(utils, a, b);
}
