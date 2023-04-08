/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:20:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/08 15:54:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = 1;
	init_structs(&a, &b);
	if (verify_args(argc, argv, &a, &b) == 1)
	{
		while (--argc >= i)
		{
			push(&a, new_node(atoi(argv[argc])), 0);
		}
		if (is_organized(a) == 1)
		{
			ft_printf("It's already organized, nothing to be done :)\n");
			exit(0);
		}
		execute(&a, &b);
		ft_printf("its organized: %d\n", is_organized(a));
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
