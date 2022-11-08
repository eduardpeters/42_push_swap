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
//needs editing
static int	get_chunk_midpoint(t_stack *stack, int size)
{
	int		i;
	int		midpoint;
	int		higher_count;
	t_stack	*current_node;

	if (!stack)
		return (0);
	higher_count = 0;
	current_node = stack;
	while (higher_count != size / 2)
	{
		i = 1;
		higher_count = 0;
		midpoint = stack->number;
		stack = stack->next;
		while (i < size)
		{
			if (stack->number > midpoint)
				higher_count++;
			stack = stack->next;
			i++;
		}
		stack = stack->next;
	}
	return (midpoint);
}
//needs editing
static int	push_above_midpoint(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	midpoint;
	int	pushed_count;
	int	node_count;

	if (!stack_a || !(*stack_a))
		return (0);
	midpoint = get_chunk_midpoint(*stack_b, size);
	pushed_count = 0;
	node_count = stack_length(*stack_a);
	while (pushed_count != node_count / 2)
	{
		if ((*stack_a)->number < midpoint)
		{
			exec_push(stack_a, stack_b, 'b');
			pushed_count++;
		}
		else if ((*stack_a)->prev->number < midpoint)
			exec_rev_rotate(stack_a, 'a');
		else
			exec_rotate(stack_a, 'a');
	}
	return (pushed_count);
}
//needs editing
void	sort_chunk_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed_count;	

	if (!stack_b || !(*stack_b))
		return ;
	if (size > 2)
	{
		// do pushes above midpoint
		pushed_count = push_above_midpoint(stack_a, stack_b, size);
		ft_putnbr(pushed_count);
		ft_putchar('\n');
		//repeat recursively with smaller chunk
		sort_chunk_b(stack_a, stack_b, size - pushed_count);
	}
	else if (size == 2)
	{
		// check if sorted, otherwise, do swap. Push both
		if (!check_sort_desc(*stack_a))
			exec_swap(stack_b, 'b');
		exec_push(stack_b, stack_a, 'a');
		exec_push(stack_b, stack_a, 'a');
	}
	else
		exec_push(stack_b, stack_a, 'a');
	return ;
}
