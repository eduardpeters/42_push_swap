/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:46:37 by epeters-          #+#    #+#             */
/*   Updated: 2023/01/06 16:49:48 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
