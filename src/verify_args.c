/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:36 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/21 15:19:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//falta trocar atoi por atol!!!! 


int ft_is_number(char *str)
{
	if (str[0] == '0' && atoi(str) == 0)
		return (1);
	else if (atoi(str) == 0)
		return (-1);
	return (1);
}

int verify_args(int argc, char **argv)
{
	int i;

	i = 1;
    if (argc < 2)
        return (-1);
    while (i < argc)
    {
		if (ft_is_number(argv[i]) == -1)
			return (panic("not all arguments are integers"));
        else if (atoi(argv[i]) > INT_MAX || atoi(argv[i]) < INT_MIN)
            return (panic("arguments outside the range of integers"));
        i++;
    }
	if (verify_doubles(argc, argv) == -1)
        return(panic("arguments with duplicate numbers"));
	return (1);
}

int verify_doubles(int argc, char **argv)
{
	int i;
	int j; 

	i = 1;
	while(i < argc)
	{
		j = i + 1;
		while(j < argc)
		{
			if(atoi(argv[i]) == atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}







