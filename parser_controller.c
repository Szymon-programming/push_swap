/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:02:42 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/27 18:55:05 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_matrix_size(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i] != NULL)
		i++;
	return (i);
}

static void	free_matrix(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i] != NULL)
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

int	*get_parsed_numbers(int argc, char *argv[], int i, int *size)
{
	int		*numbers;
	int		split_argc;
	char	**split_argv;

	if (argc - i > 1)
	{
		*size = (argc - i);
		return (parser(argc, argv, i));
	}
	split_argv = ft_split(argv[i], ' ');
	if (!split_argv)
		return (NULL);
	split_argc = get_matrix_size(split_argv);
	*size = split_argc;
	numbers = parser(split_argc, split_argv, 0);
	free_matrix(split_argv);
	return (numbers);
}
