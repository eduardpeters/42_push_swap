/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:07:29 by epeters-          #+#    #+#             */
/*   Updated: 2022/10/31 10:42:06 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	fill_stack(char **args, t_stack **curr, t_stack **start,
		t_stack **end)
{
	t_stack	*new_node;
	int		current_arg;

	current_arg = 1;
	while (args[current_arg])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (0);
		new_node->number = ft_atoi(args[current_arg]);
		new_node->next = *start;
		new_node->prev = *end;
		(*curr)->next = new_node;
		*end = new_node;
		*curr = (*curr)->next;
		current_arg++;
	}
	return (1);
}

t_stack	*initialize_stack(char **args)
{
	t_stack	*start;
	t_stack	*end;
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->number = ft_atoi(args[0]);
	new_stack->next = new_stack;
	new_stack->prev = new_stack;
	start = new_stack;
	end = new_stack;
	if (!fill_stack(args, &new_stack, &start, &end))
	{
		free_stack(&new_stack);
		return (NULL);
	}
	end = new_stack;
	new_stack = new_stack->next;
	new_stack->prev = end;
	return (new_stack);
}

int	stack_length(t_stack *stack)
{
	int		length;
	t_stack	*current_node;

	if (!stack)
		return (0);
	length = 1;
	current_node = stack;
	while (current_node->next != stack)
	{
		current_node = current_node->next;
		length++;
	}
	return (length);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*next_node;

	current_node = (*stack)->next;
	while (current_node != *stack)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(*stack);
}
