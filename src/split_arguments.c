/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:28:59 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/27 20:30:14 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_arguments(char **new_args)
{
	int	current_arg;

	current_arg = 0;
	while (new_args[current_arg])
		free(new_args[current_arg++]);
	free(new_args);
	return ;
}

static int	check_args_numbers(int argc, char **argv)
{
	int	i;
	int	current_arg;
	int	number_count;

	current_arg = 0;
	while (current_arg < argc)
	{
		i = 0;
		number_count = 0;
		while (argv[current_arg][i])
		{
			if (ft_isdigit(argv[current_arg][i]))
				number_count++;
			i++;
		}
		if (number_count == 0)
			return (0);
		current_arg++;
	}
	return (1);
}

char	**split_arguments(int argc, char **argv)
{
	int		current_arg;
	char	**new_args;
	char	*joined_str;
	char	*temp_str;

	if (!check_args_numbers(argc, argv))
		return (NULL);
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
