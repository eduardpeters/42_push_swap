/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:40:09 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/08 12:38:24 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <stdlib.h>
//# include <unistd.h>

# include "libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* push_swap.c */
int		main(int argc, char **argv);
int		check_sort(t_stack *stack);
int		check_sort_desc(t_stack *stack);

/* split_arguments.c */
char	**split_arguments(int argc, char **argv);
void	free_split_arguments(char **new_args);

/* parse_arguments.c */
t_stack	*parse_arguments(char **new_args);

/* manage_stack.c */
t_stack	*initialize_stack(char **args);
void	free_stack(t_stack **stack);
int		stack_length(t_stack *stack);

/* sorting_a.c */
void	sort_stack_a(t_stack **stack_a, t_stack **stack_b);

/* sorting_b.c */
void	sort_chunk_b(t_stack **stack_a, t_stack **stack_b, int size);

/* stack_rotations.c */
void	exec_rotate(t_stack **stack, char c);
void	exec_rev_rotate(t_stack **stack, char c);
void	exec_both_rotate(t_stack **stack_a, t_stack **stack_b, char c);

/* stack_swaps.c */
void	exec_swap(t_stack **stack, char c);

/* stack_pushes.c */
void	exec_push(t_stack **stack_from, t_stack **stack_to, char c);

/* testing.c */
void	run_tests(t_stack **stack_a);

#endif