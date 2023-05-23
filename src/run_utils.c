/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:45:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 18:17:01 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	run_utils(t_utils *u, t_stack *a, t_stack *b)
{
	while (u->a_rotate != 0 || u->b_rotate != 0 || u->a_reverse_rotate != 0 || \
	u->b_reverse_rotate != 0 || u->rr != 0 || u->rrr != 0)
	{
		if (u->a_rotate > 0)
		{
			rotate(a, 1);
			u->a_rotate--;
		}
		if (u->b_rotate > 0)
		{
			rotate(b, 1);
			u->b_rotate--;
		}
		if (u->rr > 0)
		{
			rr(a, b);
			u->rr--;
		}
		run_reverse_rotate(u, a, b);
	}
}

void	run_reverse_rotate(t_utils *u, t_stack *a, t_stack *b)
{
	if (u->a_reverse_rotate > 0)
	{
		reverse_rotate(a, 1);
		u->a_reverse_rotate--;
	}
	if (u->b_reverse_rotate > 0)
	{
		reverse_rotate(b, 1);
		u->b_reverse_rotate--;
	}
	if (u->rrr > 0)
	{
		rrr(a, b);
		u->rrr--;
	}
}
