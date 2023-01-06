/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:43:39 by epeters-          #+#    #+#             */
/*   Updated: 2023/01/06 16:50:23 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**new_args;

	if (argc < 2)
		return (1);
	new_args = split_arguments(argc -1, argv + 1);
	if (!new_args)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = parse_arguments(new_args);
	free_split_arguments(new_args);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	route_sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}
