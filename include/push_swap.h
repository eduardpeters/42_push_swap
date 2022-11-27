/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:40:09 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/27 19:00:07 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		check_sort_asc(t_stack *stack, int size);
int		check_sort_desc(t_stack *stack, int size);

/* split_arguments.c */
char	**split_arguments(int argc, char **argv);
void	free_split_arguments(char **new_args);

/* parse_arguments.c */
t_stack	*parse_arguments(char **new_args);

/* manage_stack.c */
t_stack	*initialize_stack(char **args);
int		stack_length(t_stack *stack);
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);

/* sorting_a.c */
void	sort_stack_a(t_stack **stack_a, t_stack **stack_b);

/* sorting_b.c */
void	sort_chunk_b(t_stack **stack_a, t_stack **stack_b, int size);

/* sort_chunk_a.c */
void	sort_chunk_a(t_stack **stack_a, t_stack **stack_b, int size);

/* chunk_helpers.c */
int		count_nodes(t_stack *stack, int size, int midpoint, char chunk);
void	rev_rotate_chunk(t_stack **stack, int rotations, char chunk);
void	rotate_chunk(t_stack **stack, int rotations, char chunk);

/* stack_rotations.c */
void	exec_rotate(t_stack **stack, char c);
void	exec_rev_rotate(t_stack **stack, char c);
void	exec_both_rotate(t_stack **stack_a, t_stack **stack_b, char c);

/* stack_swaps.c */
void	exec_swap(t_stack **stack, char c);

/* stack_pushes.c */
void	exec_push(t_stack **stack_from, t_stack **stack_to, char c);

/* route_sort.c */
void	route_sort(t_stack **stack_a);

/* sort_three.c */
void	sort_three(t_stack **stack_a);

/* sort_four.c */
void	sort_up_to_four(t_stack **stack_a, t_stack **stack_b, int size);

#endif
