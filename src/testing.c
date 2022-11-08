/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:53:42 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 12:35:37 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h> //remove!!

static void	print_stack(t_stack *stack)
{
	t_stack	*i;

	if (!stack)
		return ;
	i = stack;
	while (i->next != stack)
	{
		ft_putnbr(i->number);
		i = i->next;
		ft_putchar(' ');
	}
	ft_putnbr(i->number);
	return ;
}

void	run_tests(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	print_stack(*stack_a);
	ft_putchar('\n');
	print_stack(stack_b);
	ft_putchar('\n');
	sort_stack_a(stack_a, &stack_b);
	print_stack(*stack_a);
	ft_putchar('\n');
	print_stack(stack_b);
	ft_putchar('\n');
	return ;
}
