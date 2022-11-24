/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:28:47 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 16:00:18 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_nodes(t_stack *stack, int size, int midpoint, char chunk)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (chunk == 'b')
		{
			if (stack->number > midpoint)
				count++;
		}
		else
		{
			if (stack->number < midpoint)
				count++;
		}
		stack = stack->next;
		i++;
	}
	return (count);
}

void	rev_rotate_chunk(t_stack **stack, int rotations, char chunk)
{
	while (rotations > 0)
	{
		exec_rev_rotate(stack, chunk);
		rotations--;
	}
	return ;
}
