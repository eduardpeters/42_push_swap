/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:38:43 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 13:04:29 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_chunk_max(t_stack *stack, int size)
{
	int		i;
	int		max;
	t_stack	*current_node;

	if (!stack)
		return (0);
	i = 1;
	max = stack->number;
	current_node = stack->next;
	while (i < size)
	{
		if (current_node->number > max)
			max = current_node->number;
		current_node = current_node->next;
		i++;
	}
	return (max);
}

static void	push_max(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max;
	int	rotations;

	if (!stack_b || !(*stack_b))
		return ;
	max = get_chunk_max(*stack_b, size);
	rotations = 0;
	while ((*stack_b)->number != max)
	{
		exec_rotate(stack_b, 'b');
		rotations++;
	}
	exec_push(stack_b, stack_a, 'a');
	while (rotations > 0)
	{
		exec_rev_rotate(stack_b, 'b');
		rotations--;
	}
	return ;
}

static void	push_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		exec_push(stack_b, stack_a, 'a');
		i++;
	}
	return ;
}

void	sort_chunk_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!stack_b || !(*stack_b))
		return ;
	if (check_sort_desc(*stack_b, size))
	{
		push_size(stack_a, stack_b, size);
	}
	else if (size > 2)
	{
		// push the max value
		push_max(stack_a, stack_b, size);
		//repeat recursively with smaller chunk
		sort_chunk_b(stack_a, stack_b, size - 1);
	}
	else if (size == 2)
	{
		// check if sorted, otherwise, do swap. Push both
		if (!check_sort_desc(*stack_b, size))
			exec_swap(stack_b, 'b');
		push_size(stack_a, stack_b, size);
		//exec_push(stack_b, stack_a, 'a');
		//exec_push(stack_b, stack_a, 'a');
	}
	else
		exec_push(stack_b, stack_a, 'a');
	return ;
}
