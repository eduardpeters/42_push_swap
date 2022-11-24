/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:04:00 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 15:07:58 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//get midpoint with size
static int	get_midpoint_a(t_stack *stack, int size)
{
	int		i;
	int		midpoint;
	int		lower_count;
	t_stack	*midpoint_node;
	t_stack	*current_node;

	if (!stack)
		return (0);
	lower_count = 0;
	midpoint_node = stack;
	while (lower_count != size / 2)
	{
		i = 0;
		lower_count = 0;
		midpoint = midpoint_node->number;
		current_node = stack;
		while (i < size)
		{
			if (current_node->number < midpoint)
				lower_count++;
			current_node = current_node->next;
			i++;
		}
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
	while (rotations > 0)
	{
		exec_rev_rotate(stack_a, 'a');
		rotations--;
	}
	return (pushed_count);
}

void	sort_chunk_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed_count;

	if (!stack_a || !(*stack_a) || check_sort_asc(*stack_a, size))
		return ;
	if (size > 2)
	{
		//get midpoint and push elements below it to b again
		pushed_count = push_below_mid_chunk(stack_a, stack_b, size);
		// call itself again
		sort_chunk_a(stack_a, stack_b, size - pushed_count);
		// go to sort chunk b finally
		sort_chunk_b(stack_a, stack_b, pushed_count);
	}
	else
	{
		if (!check_sort_asc(*stack_a, size))
			exec_swap(stack_a, 'a');
	}
	return ;
}
