/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:33:19 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 11:34:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("== a ==\n");
	if (a->top != NULL )
	{
		while (i++ < a->size)
		{
			printf("  %d   \n", a->top->data);
			a->top = a->top->next;
		}
	}
	ft_printf("== b ==\n");
	if (b->top != NULL)
	{
		i = 0;
		while (i++ < b->size)
		{
			printf("  %d   \n", b->top->data);
			b->top = b->top->next;
		}
	}
	ft_printf("=======\n\n");
	return (1);
}

void	print_info(t_stack stack)
{
	ft_printf("==== info stack %c ====\n", stack.charac);
	ft_printf("->top node: %d\n", stack.top->data);
	ft_printf("next do top node: %d\n", stack.top->next->data);
	ft_printf("next do next do top node (segundo): %d\n", \
	stack.top->next->next->data);
	ft_printf("prev do top node: %d\n", stack.top->prev->data);
	ft_printf("last node: %d\n", find_last_node(stack)->data);
	ft_printf("prev do last node: %d\n", find_last_node(stack)->prev->data);
	ft_printf("next do last node: %d\n", find_last_node(stack)->next->data);
	ft_printf("->size da stack: %d\n\n", stack.size);
}

void	print_utils(t_utils *utils)
{
	ft_printf("\n===== utils =====\n");
	ft_printf("a_data: %d\n", utils->a_data);
	ft_printf("b_data: %d\n", utils->b_data);
	ft_printf("a_rotate: %d\n", utils->a_rotate);
	ft_printf("b_rotate: %d\n", utils->b_rotate);
	ft_printf("a_reverse_rotate: %d\n", utils->a_reverse_rotate);
	ft_printf("b_reverse_rotate: %d\n", utils->b_reverse_rotate);
	ft_printf("rr: %d\n", utils->rr);
	ft_printf("rrr: %d\n\n", utils->rrr);
}
