/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:48 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 11:24:49 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(int data, t_stack stack)
{
	int	i;

	i = -1;
	while (++i < stack.size)
	{
		if (stack.top->data == data)
			return (i);
		stack.top = stack.top->next;
	}
	return (i);
}
