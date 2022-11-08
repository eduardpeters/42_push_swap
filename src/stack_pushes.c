/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:08:26 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 11:07:31 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	remove_head(t_stack **stack)
{
	if (*stack == (*stack)->next)
		*stack = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
	}
	return ;
}

static int	push_stack(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*pushed_node;

	if (!stack_from || !(*stack_from) || !stack_to)
		return (0);
	pushed_node = *stack_from;
	remove_head(stack_from);
	if (*stack_to)
	{
		(*stack_to)->prev->next = pushed_node;
		pushed_node->prev = (*stack_to)->prev;
		(*stack_to)->prev = pushed_node;
		pushed_node->next = *stack_to;
		*stack_to = pushed_node;
	}
	else
	{
		*stack_to = pushed_node;
		(*stack_to)->prev = *stack_to;
		(*stack_to)->next = *stack_to;
	}
	return (1);
}

void	exec_push(t_stack **stack_from, t_stack **stack_to, char c)
{
	int	outcome;

	outcome = push_stack(stack_from, stack_to);
	if (outcome)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
