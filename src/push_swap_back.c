/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:38:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 15:55:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_cheapest(t_stack *origin, t_stack *dest, t_stack *tmp, t_utils *u)
{
	int		i;
	int		sum;
	t_utils	*tmp_utils;

	i = 0;
	tmp_utils = u;
	sum = sum_moves(u);
	while (i < tmp->size)
	{
		count_moves(tmp->top->data, origin, u);
		count_moves(find_perfect_match(tmp->top->data, dest), dest, u);
		sum_rr_rrr(u);
		if (sum_moves(u) == 0 || sum_moves(u) < sum)
		{
			sum = sum_moves(u);
			tmp_utils = u;
			if (sum_moves(u) == 0 || sum_moves(u) == 1)
				break ;
		}
		else
			init_utils(u);
		tmp->top = tmp->top->next;
		i++;
	}
	free_stack(tmp);
}

t_utils	push_swap_back(t_stack *origin, t_stack *dest)
{
	t_utils	utils;
	t_utils	tmp_utils;
	t_stack	tmp;
	int		i;

	i = 0;
	init_utils (&utils);
	init_utils (&tmp_utils);
	tmp = copy_stack(origin);
	count_moves(tmp.top->data, origin, &utils);
	count_moves(find_perfect_match(tmp.top->data, dest), dest, &utils);
	tmp_utils = utils;
	find_cheapest(origin, dest, &tmp, &utils);
	free_stack(&tmp);
	return (tmp_utils);
}

void	push_back(t_stack *a, t_stack *b)
{
	t_utils	utils;

	init_utils(&utils);
	count_moves(find_perfect_match(b->top->data, a), a, &utils);
	run_utils(&utils, a, b);
	push(a, new_node(pop(b)), 1);
}
