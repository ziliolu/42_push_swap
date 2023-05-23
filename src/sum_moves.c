/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:22:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/12 18:06:16 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sum_rr_rrr(t_utils *u)
{
	if (u->a_rotate != 0 && u->b_rotate != 0)
		sum_rotates(u);
	else if (u->a_reverse_rotate != 0 && u->b_reverse_rotate != 0)
		sum_reverse_rotates(u);
}

void	sum_reverse_rotates(t_utils *u)
{
	if (u->a_reverse_rotate == u->b_reverse_rotate)
	{
		u->rrr = u->a_reverse_rotate;
		u->a_reverse_rotate = 0;
		u->b_reverse_rotate = 0;
	}
	else
	{
		if (u->a_reverse_rotate > u->b_reverse_rotate)
		{
			u->rrr = u->a_reverse_rotate - \
			(u->a_reverse_rotate - u->b_reverse_rotate);
			u->a_reverse_rotate = u->a_reverse_rotate - u->b_reverse_rotate;
			u->b_reverse_rotate = 0;
		}
		else
		{
			u->rrr = u->b_reverse_rotate - \
			(u->b_reverse_rotate - u->a_reverse_rotate);
			u->b_reverse_rotate = u->b_reverse_rotate - u->a_reverse_rotate;
			u->a_reverse_rotate = 0;
		}
	}
}

void	sum_rotates(t_utils *utils)
{
	if (utils->a_rotate == utils->b_rotate)
	{
		utils->rr = utils->a_rotate;
		utils->a_rotate = 0;
		utils->b_rotate = 0;
	}
	else
	{
		if (utils->a_rotate > utils->b_rotate)
		{
			utils->rr = utils->a_rotate - (utils->a_rotate - utils->b_rotate);
			utils->a_rotate = utils->a_rotate - utils->b_rotate;
			utils->b_rotate = 0;
		}
		else
		{
			utils->rr = utils->b_rotate - (utils->b_rotate - utils->a_rotate);
			utils->b_rotate = utils->b_rotate - utils->a_rotate;
			utils->a_rotate = 0;
		}
	}
}
