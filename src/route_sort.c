/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:49:52 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/27 19:00:38 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	route_sort(t_stack **stack_a)
{
	int		stack_size;
	t_stack	*stack_b;

	if (check_sort(*stack_a))
		return ;
	stack_b = NULL;
	stack_size = stack_length(*stack_a);
	if (stack_size == 2)
		exec_swap(stack_a, 'a');
	else if (stack_size < 5)
		sort_up_to_four(stack_a, &stack_b, stack_size);
	else
		sort_stack_a(stack_a, &stack_b);
	return ;
}
