/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:02:42 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// zlicza ilość słów zwróconych przez splita, przekazuje tą ilość do
// parsera, żeby wiedzieć ile miejsca alokować, jest to nowe argc
static int	get_matrix_size(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i] != NULL)
		i++;
	return (i);
}

// zwalnia kazdą szufladkę po kolei, po czym zwalnia cały obiekt (szafę)
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

// funkcja zarządzająca, czy trzeba zesplitować wartości
// które wpadły jako "1 2 3 4 5"
// czy od razu wrzucić wartości 1 2 3 4 5
int	*get_parsed_numbers(int argc, char *argv[], int i, int *size)
{
	int		*numbers;
	int		split_argc;
	char 	**split_argv;

	split_argv = ft_split(argv[i], ' ');
	split_argc = get_matrix_size(split_argv);
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
