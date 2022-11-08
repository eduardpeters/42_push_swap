/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:39:01 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 13:04:31 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_midpoint(t_stack *stack)
{
	int		i;
	int		midpoint;
	int		lower_count;
	int		node_count;

	if (!stack)
		return (0);
	lower_count = 0;
	node_count = stack_length(stack);
	while (lower_count != node_count / 2)
	{
		i = 1;
		lower_count = 0;
		midpoint = stack->number;
		stack = stack->next;
		while (i < node_count)
		{
			if (stack->number < midpoint)
				lower_count++;
			stack = stack->next;
			i++;
		}
		stack = stack->next;
	}
	return (midpoint);
}

static int	push_below_midpoint(t_stack **stack_a, t_stack **stack_b)
{
	int	midpoint;
	int	pushed_count;
	int	node_count;

	if (!stack_a || !(*stack_a))
		return (0);
	midpoint = get_midpoint(*stack_a);
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

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed_count;

	if (!stack_a || !(*stack_a))
		return ;
	if (stack_length(*stack_a) > 2)
	{
		// do pushes below midpoint
		pushed_count = push_below_midpoint(stack_a, stack_b);
		ft_putnbr(pushed_count);
		ft_putchar('\n');
		sort_stack_a(stack_a, stack_b);
		// get from B chunk with pushed_count size
		sort_chunk_b(stack_a, stack_b, pushed_count);
	}
	else
	{
		// check if sorted, otherwise, do swap
		if (!check_sort(*stack_a))
			exec_swap(stack_a, 'a');
	}
	return ;
}
