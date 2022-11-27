/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:59:28 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/24 19:14:35 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	decide_rotation(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		exec_rotate(stack_a, 'a');
	else
		exec_rev_rotate(stack_a, 'a');
	return ;
}

void	sort_three(t_stack **stack_a)
{
	if (check_sort(*stack_a))
		return ;
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		if ((*stack_a)->number < (*stack_a)->prev->number)
		{
			exec_swap(stack_a, 'a');
			return ;
		}
		if ((*stack_a)->next->number > (*stack_a)->prev->number)
			exec_swap(stack_a, 'a');
	}
	else
	{
		if ((*stack_a)->number < (*stack_a)->prev->number)
			exec_swap(stack_a, 'a');
	}	
	decide_rotation(stack_a);
	return ;
}
