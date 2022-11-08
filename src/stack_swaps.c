/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:09:56 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 10:54:29 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || stack_length(*stack) == 1)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->prev->next = second;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	exec_swap(t_stack **stack, char c)
{
	int	outcome;

	outcome = swap_stack(stack);
	if (outcome)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
