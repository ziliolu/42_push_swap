/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:25:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 11:26:22 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_structs(t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	a->size = 0;
	b->size = 0;
	a->charac = 'a';
	b->charac = 'b';
}

t_utils	*init_utils(t_utils *utils)
{
	utils->a_data = 0;
	utils->b_data = 0;
	utils->a_rotate = 0;
	utils->b_rotate = 0;
	utils->a_reverse_rotate = 0;
	utils->b_reverse_rotate = 0;
	utils->rr = 0;
	utils->rrr = 0;
	return (utils);
}
