/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:04:00 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 16:01:59 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_midpoint_a(t_stack *stack, int size)
{
	int		midpoint;
	int		lower_count;
	t_stack	*midpoint_node;

	if (!stack)
		return (0);
	lower_count = 0;
	midpoint_node = stack;
	while (lower_count != size / 2)
	{
		midpoint = midpoint_node->number;
		lower_count = count_nodes(stack, size, midpoint, 'a');
		midpoint_node = midpoint_node->next;
	}
	return (midpoint);
}

static int	push_below_mid_chunk(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	midpoint;
	int	pushed_count;
	int	rotations;

	if (!stack_a || !(*stack_a))
		return (0);
	midpoint = get_midpoint_a(*stack_a, size);
	pushed_count = 0;
	rotations = 0;
	while (pushed_count != size / 2)
	{
		if ((*stack_a)->number < midpoint)
		{
			exec_push(stack_a, stack_b, 'b');
			pushed_count++;
		}
		else
		{
			exec_rotate(stack_a, 'a');
			rotations++;
		}
	}
	rev_rotate_chunk(stack_a, rotations, 'a');
	return (pushed_count);
}

void	sort_chunk_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed_count;

	if (!stack_a || !(*stack_a) || check_sort_asc(*stack_a, size))
		return ;
	if (size > 2)
	{
		pushed_count = push_below_mid_chunk(stack_a, stack_b, size);
		sort_chunk_a(stack_a, stack_b, size - pushed_count);
		sort_chunk_b(stack_a, stack_b, pushed_count);
	}
	else
	{
		if (!check_sort_asc(*stack_a, size))
			exec_swap(stack_a, 'a');
	}
	return ;
}
