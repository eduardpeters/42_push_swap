/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:28:17 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/27 17:32:49 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*current_node;

	min = stack->number;
	current_node = stack->next;
	while (current_node != stack)
	{
		if (current_node->number < min)
			min = current_node->number;
		current_node = current_node->next;
	}
	return (min);
}

static void	rotate_to_order(t_stack **stack_a, int min)
{
	int		rot_fwd;
	int		rot_rev;
	t_stack	*current_node;

	rot_fwd = 0;
	rot_rev = 0;
	current_node = *stack_a;
	while (current_node->number != min)
	{
		current_node = current_node->next;
		rot_fwd++;
	}
	current_node = *stack_a;
	while (current_node->number != min)
	{
		current_node = current_node->prev;
		rot_rev++;
	}
	if (rot_fwd <= rot_rev)
		rotate_chunk(stack_a, rot_fwd, 'a');
	else
		rev_rotate_chunk(stack_a, rot_rev, 'a');
	return ;
}

static void	insert_fourth(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->number < (*stack_a)->number)
		exec_push(stack_b, stack_a, 'a');
	else if ((*stack_b)->number > (*stack_a)->prev->number)
	{
		exec_push(stack_b, stack_a, 'a');
		exec_rotate(stack_a, 'a');
	}
	else
	{
		while (*stack_b)
		{
			exec_rotate(stack_a, 'a');
			if ((*stack_b)->number < (*stack_a)->number)
				exec_push(stack_b, stack_a, 'a');
		}
		rotate_to_order(stack_a, get_min(*stack_a));
	}
	return ;
}

void	sort_up_to_four(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!stack_a)
		return ;
	if (size > 3)
		exec_push(stack_a, stack_b, 'b');
	sort_three(stack_a);
	if (*stack_b)
		insert_fourth(stack_a, stack_b);
	return ;
}
