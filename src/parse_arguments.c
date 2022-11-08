/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:29:29 by epeters-          #+#    #+#             */
/*   Updated: 2022/09/15 19:48:46 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_int_limits(char *str)
{
	int		length;
	long	nbr;

	length = ft_strlen(str);
	if (length < 10)
		return (1);
	if (length > 11)
		return (0);
	if (length == 11 && !(*str == '-' || *str == '+'))
		return (0);
	nbr = ft_atol(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

static int	check_number(char *str)
{
	if (!str)
		return (0);
	if (!check_int_limits(str))
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	else
		return (1);
}

static int	check_duplicates(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i != stack->prev)
	{
		j = i->next;
		while (j != stack)
		{
			if (i->number == j->number)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static int	get_arg_size(char **args)
{
	int	size;

	size = 0;
	while (*args++)
		size++;
	return (size);
}

t_stack	*parse_arguments(char **args)
{
	int		current_arg;
	int		arg_size;
	t_stack	*stack_a;

	current_arg = 0;
	arg_size = get_arg_size(args);
	while (current_arg < arg_size)
	{
		if (!check_number(args[current_arg]))
			return (NULL);
		current_arg++;
	}
	stack_a = initialize_stack(args);
	if (check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		return (NULL);
	}
	return (stack_a);
}
