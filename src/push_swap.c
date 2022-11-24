/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:43:39 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 16:50:27 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h> //remove getchar before returns!!

int	check_sort(t_stack *stack)
{
	t_stack	*i;

	i = stack;
	while (i->next != stack)
	{
		if (i->number > i->next->number)
			return (0);
		i = i->next;
	}
	return (1);
}

int	check_sort_asc(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	check_sort_desc(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->number < stack->next->number)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

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
		getchar(); //remove!!
		return (1);
	}
	stack_a = parse_arguments(new_args);
	free_split_arguments(new_args);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		getchar(); //remove!!
		return (1);
	}
	route_sort(&stack_a);
	free_stack(&stack_a);
	getchar(); //remove!!
	return (0);
}
