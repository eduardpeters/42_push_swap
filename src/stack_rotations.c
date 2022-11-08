/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:39 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 11:37:52 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return (0);
	*stack = (*stack)->next;
	return (1);
}

static int	rev_rotate_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

void	exec_rotate(t_stack **stack, char c)
{
	int	outcome;

	outcome = rotate_stack(stack);
	if (outcome)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	exec_rev_rotate(t_stack **stack, char c)
{
	int	outcome;

	outcome = rev_rotate_stack(stack);
	if (outcome)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	exec_both_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	if (c == 'r')
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		write(1, "rrr\n", 4);
	}
	else
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		write(1, "rr\n", 3);
	}
}
