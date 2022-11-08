/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:28:59 by epeters-          #+#    #+#             */
/*   Updated: 2022/09/15 18:23:36 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_arguments(char **new_args)
{
	int	current_arg;

	current_arg = 0;
	while (new_args[current_arg])
		free(new_args[current_arg++]);
}

char	**split_arguments(int argc, char **argv)
{
	int		current_arg;
	char	**new_args;
	char	*joined_str;
	char	*temp_str;

	joined_str = ft_strdup(argv[0]);
	current_arg = 1;
	while (current_arg < argc)
	{
		temp_str = joined_str;
		joined_str = ft_strjoin(joined_str, " ");
		free(temp_str);
		temp_str = joined_str;
		joined_str = ft_strjoin(joined_str, argv[current_arg]);
		free(temp_str);
		current_arg++;
	}
	new_args = ft_split(joined_str, ' ');
	free(joined_str);
	return (new_args);
}
