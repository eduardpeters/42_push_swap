/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:38:43 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 16:02:02 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_midpoint_b(t_stack *stack, int size)
{
	int		midpoint;
	int		higher_count;
	t_stack	*midpoint_node;

	if (!stack)
		return (0);
	higher_count = 0;
	midpoint_node = stack;
	while (higher_count != size / 2)
	{
		midpoint = midpoint_node->number;
		higher_count = count_nodes(stack, size, midpoint, 'b');
		midpoint_node = midpoint_node->next;
	}
	return (midpoint);
}

static int	push_above_mid_chunk(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	midpoint;
	int	pushed_count;
	int	rotations;

	if (!stack_b || !(*stack_b))
		return (0);
	midpoint = get_midpoint_b(*stack_b, size);
	pushed_count = 0;
	rotations = 0;
	while (pushed_count != size / 2)
	{
		if ((*stack_b)->number > midpoint)
		{
			exec_push(stack_b, stack_a, 'a');
			pushed_count++;
		}
		else
		{
			exec_rotate(stack_b, 'b');
			rotations++;
		}
	}
	rev_rotate_chunk(stack_b, rotations, 'b');
	return (pushed_count);
}

static void	push_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

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
	int	pushed_count;

	if (!stack_b || !(*stack_b))
		return ;
	if (check_sort_desc(*stack_b, size))
		push_size(stack_a, stack_b, size);
	else if (size > 2)
	{
		pushed_count = push_above_mid_chunk(stack_a, stack_b, size);
		sort_chunk_a(stack_a, stack_b, pushed_count);
		sort_chunk_b(stack_a, stack_b, size - pushed_count);
	}
	else if (size == 2)
	{
		if (!check_sort_desc(*stack_b, size))
			exec_swap(stack_b, 'b');
		push_size(stack_a, stack_b, size);
	}
	else
		exec_push(stack_b, stack_a, 'a');
	return ;
}
