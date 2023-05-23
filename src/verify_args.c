/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:51:39 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/04/13 12:52:30 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_number(char *str)
{
	if (str[0] == '0' && atoi(str) == 0)
		return (1);
	else if (atol(str) == 0)
		return (-1);
	return (1);
}

int	verify_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (-1);
	while (i < argc)
	{
		if (ft_is_number(argv[i]) == -1)
			return (panic(a, b));
		else if (atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
			return (panic (a, b));
		i++;
	}
	if (verify_doubles(argc, argv) == -1)
		return (panic(a, b));
	return (1);
}

int	verify_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atol(argv[i]) == atol(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
